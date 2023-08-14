#ifndef SERVEREXCEPTIONS_HPP
# define SERVEREXCEPTIONS_HPP

# include "webserv.h"

class ServerException: public std::exception {
	private:
		std::string _errCode;
		std::string _res;
		int _fd;

	public:
		ServerException(std::string errCode, std::string res, int fd) : exception(), _errCode(errCode), _res(res), _fd(fd) { return; }

		const char * what() const throw ()
		{
			std::string resp;
			if (_errCode == "500") {
				std::cerr << RED << "500: Something goes wrong." << RESET << std::endl;
				close(_fd);
			}
			const char * c_resp = _res.c_str();
			return c_resp;
		}
		~ServerException() throw() {}
};

#endif
