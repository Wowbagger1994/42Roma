# include "webserv.h"

class OpenSocketException : public std::exception {
	private:
		std::string _message;

	public:
		OpenSocketException(std::string message) : exception(), _message(message){}

		const char * what() const throw () {
			std::string resp("An error occurred while opening the socket: ");
			resp.append(_message);
			const char * c_resp = resp.c_str();
			return c_resp;
		}
		~OpenSocketException() throw(){}
};
