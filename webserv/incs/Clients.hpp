#ifndef CLIENTS_HPP
# define CLIENTS_HPP

# include "webserv.h"

class Clients
{
private:
	struct client_data
	{
		int fd;
		int evIdent;
		Configuration *config;
		client_data(int conn, int evId) : fd(conn), evIdent(evId){ return; }
	} ;

	std::vector<client_data> _clients;
public:
	Clients();
	~Clients();

	client_data *get_conn(int fd);
	int conn_add(int fd, int evIdent);
	int conn_del(int fd);
};

#endif
