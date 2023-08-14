# include "Clients.hpp"

Clients::Clients() { return ; }

Clients::~Clients()
{
}

Clients::client_data *Clients::get_conn(int fd) {
	int n = 0;
	std::vector<client_data>::iterator i = _clients.begin();

	for ( ; i != _clients.end(); i++, n++)
		if ((*i).fd == fd)
			return &(*i);
	return NULL;
}

int Clients::conn_add(int fd, int evIdent) {
	if (fd < 1) return -1;
	int flags = fcntl(fd, F_GETFL, 0);
	assert(flags >= 0);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);
	_clients.push_back(client_data(fd, evIdent));
	return 0;
}

int Clients::conn_del(int fd) {
	if (fd < 1) return -1;
	client_data* cd = get_conn(fd);
	if (!cd) return -1;
	std::vector<client_data>::iterator it = _clients.begin();
	for ( ; (*it).fd != (*cd).fd; it++) ;
	_clients.erase(it);
	return close(fd);
}
