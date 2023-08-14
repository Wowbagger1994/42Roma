#include "webserv.h"

bool run = 1;
const int kQueue = kqueue();

static void signal_handler(int i)
{
	if (i == SIGINT)
		run = 0;
}

static int findServerByFD(std::vector<Server *> servers, int ident)
{
	int i = 0;
	std::vector<Server *>::iterator it = servers.begin();
	for (; it != servers.end(); it++, i++)
		if ((**it).getSockFD() == ident)
			return i;
	return -1;
}

std::vector<Server *> initServers(std::map<std::string, std::vector<Configuration> > portConfigs)
{
	std::map<std::string, std::vector<Configuration> >::iterator it = portConfigs.begin();
	std::vector<Server *> servers;

	for (; it != portConfigs.end(); it++)
	{
		Server *s = new Server((*it).second[0].getPort(), (*it).second[0].getHost(), &((*it).second[0]));
		try
		{
			s->connect(kQueue);
		}
		catch (const OpenSocketException &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		servers.push_back(s);
	}
	return servers;
}

int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		std::cerr << RED << "Error: Wrong numbers of arguments" << RESET << std::endl;
		return 1;
	}
	ConfigurationFile cf(argc == 1 ? DEFAULT_PATH : argv[1]);
	signal(SIGINT, signal_handler);
	execAutoindex();

	std::vector<Server *> servers = initServers(cf.getMapConfigs());

	Clients clients;

	struct kevent evList[MAX_EVENTS];

	while (run)
	{
		std::string bufferStr;
		int num_events = kevent(kQueue, NULL, 0, evList, MAX_EVENTS, NULL);
		for (int i = 0; i < num_events; i++)
		{
			int index = findServerByFD(servers, evList[i].ident);
			if (index != -1)
			{
				ssize_t addrlen = sizeof(sockaddr);
				int connection = accept(evList[i].ident, (struct sockaddr *)(*servers[index]).getSockAddr(), (socklen_t *)&addrlen);
				try
				{
					if (clients.conn_add(connection, evList[i].ident))
					{
						ResponseHeader resHeader(NULL, std::make_pair("500", DEFAULT_ERROR_PATH));
						throw ServerException("500", resHeader.makeResponse(500), connection);
					}
					else
					{
						EV_SET((*servers[index]).getEvSet(), connection, EVFILT_READ, EV_ADD, 0, 0, NULL);
						kevent(kQueue, (*servers[index]).getEvSet(), 1, NULL, 0, NULL);
					}
				}
				catch (const ServerException &e)
				{
					e.what();
				}
			}
			else if (evList[i].filter == EVFILT_READ)
			{
				Configuration config;
				char buffer[8192];
				index = findServerByFD(servers, clients.get_conn(evList[i].ident)->evIdent);
				size_t totalBytesRead = 0;
				int bytesRead = 0;
				do
				{
					bytesRead = recv(evList[i].ident, buffer, 8192, 0);
					totalBytesRead += bytesRead;
					if (bytesRead > 0)
						bufferStr.append(buffer, bytesRead);
					usleep(100);
				} while (bytesRead > 0);
				// print header request
				// for (size_t i = 0; i < totalBytesRead + 1; i++)
				// 	std::cout << bufferStr[i];
				RequestHeader reqHeader = RequestHeader(bufferStr, totalBytesRead + 1);
				try
				{
					config = cf.getConfig((*servers[index]).getHostPort(), reqHeader.getHost());
					if (config.isEmpty())
						throw std::exception();
				}
				catch (const std::out_of_range &e)
				{
					continue;
				}
				catch (const std::exception &e)
				{
					std::cout << RED << "Error: no vaiable configuration" << RESET << std::endl;
					continue;
				}
				ResponseHeader resHeader = ResponseHeader(servers[index], &reqHeader, &config);
				std::string resp;
				try
				{
					if (reqHeader.getMethod() == "POST" && reqHeader.getBody().length() > config.getLimitSizeBody())
					{
						resHeader = ResponseHeader(NULL, std::make_pair("413", config.getErrorPath("413")));
						throw ServerException(resHeader.getError().first,
							resHeader.makeResponse(std::atoi(resHeader.getError().first.c_str())),
							evList[i].ident);
					}
					else
					{
						if (!config.getRedirectionCode())
							resp.append(resHeader.makeResponse(200));
						else
						{
							resp.append(resHeader.makeResponse(config.getRedirectionCode()));
							std::string redir("Location: ");
							redir.append(config.getRedirectionUrl());
							redir.append("\r\n");
							resp.insert(resp.find('\n') + 1, redir);
						}
						if (!resHeader.getError().first.empty())
						{
							resHeader = ResponseHeader(NULL, resHeader.getError());
							throw ServerException(resHeader.getError().first,
								resHeader.makeResponse(std::atoi(resHeader.getError().first.c_str())),
								evList[i].ident);
						}
					}
				}
				catch (const ServerException &e)
				{
					resp = e.what();
				}
				std::string respChunck;
				int dataSent = 0;
				do
				{
					respChunck = resp.substr(0, 35000);
					dataSent = send(evList[i].ident, respChunck.c_str(), respChunck.size(), 0);
					if (dataSent < 0)
						break;
					resp = resp.substr(dataSent);
				} while (resp.size());
				bufferStr.clear();
				index = findServerByFD(servers, clients.get_conn(evList[i].ident)->evIdent);
				EV_SET((*servers[index]).getEvSet(), evList[i].ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
				kevent(kQueue, (*servers[index]).getEvSet(), 1, NULL, 0, NULL);
				clients.conn_del(evList[i].ident);
				usleep(100);
			}
		}
	}

	std::cout << RED << "EXIT" << RESET << std::endl;
	close(kQueue);
	std::vector<Server *>::iterator i = servers.begin();
	for (; i != servers.end(); i++)
	{
		(*i)->disconnect();
		delete (*i);
	}
	return 0;
}
