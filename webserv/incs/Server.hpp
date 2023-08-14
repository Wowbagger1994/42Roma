#ifndef SERVER_HPP
#define SERVER_HPP

# include "webserv.h"

class Configuration;

class Server {
	private:
		int _sockfd;
		int _port;
		std::string _host;
		sockaddr_in _sockAddr;
		struct kevent _evSet;
		Configuration *_config;
	public:
		Server(unsigned int port, std::string host, Configuration *config);
		~Server();

		void connect(int kQueue);
		void disconnect();
		int getSockFD() { return _sockfd; }
		int getPort() { return _port; }
		std::string getHost() { return _host; }
		std::string getHostPort()
		{
			std::string hostPort = _host;
			hostPort.append(":");
			return hostPort.append(std::to_string(_port));
		}
		sockaddr_in* getSockAddr() { return &_sockAddr; };
		struct kevent* getEvSet() { return &_evSet; };
		Configuration getConfig();
};

#endif
