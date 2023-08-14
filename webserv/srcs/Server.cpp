# include "Server.hpp"

Server::Server(unsigned int port, std::string host, Configuration *config) : _port(port), _host(host), _config(config) {}

Server::~Server() {}

void Server::connect(int kQueue) {
	_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (_sockfd == -1) {
		throw OpenSocketException(std::string("Failed to create socket. errno: ").append(std::to_string(errno)));
	}
	_sockAddr.sin_family = AF_INET;
	if ((_sockAddr.sin_addr.s_addr = inet_addr(_host.c_str())) == INADDR_NONE) {
		throw OpenSocketException(std::string("Host ").append(std::string(_host)).append(" is not valid."));
	}
	bool b = 1;
	setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &b, sizeof(int));
	setsockopt(_sockfd, SOL_SOCKET, SO_NOSIGPIPE, &b, sizeof(int));
	_sockAddr.sin_port = htons(_port);
	if (bind(_sockfd, (struct sockaddr*)&_sockAddr, sizeof(_sockAddr)) < 0) {
		throw OpenSocketException(std::string("Failed to bind port ").append(std::to_string(_port)).append(". errno: ").append(std::to_string(errno)));
	}
	if (listen(_sockfd, 10) < 0) {
		throw OpenSocketException(std::string("Failed to listen on socket. errno: ").append(std::to_string(errno)));
	}
	EV_SET(&_evSet, _sockfd, EVFILT_READ, EV_ADD, 0, 0, NULL);
	kevent(kQueue, &_evSet, 1, NULL, 0, NULL);
	std::cout << GREEN << "Connected to host: " << BLUE << _host << GREEN << " and port: " << BLUE << _port << RESET <<std::endl;
}

void Server::disconnect() {
	close(_sockfd);
}

Configuration Server::getConfig() {
	return *_config;
}
