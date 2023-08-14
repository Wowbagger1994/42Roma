#ifndef REQUEST_HEADER_HPP
# define REQUEST_HEADER_HPP

# include "webserv.h"

class RequestHeader
{
	private:
		std::map<std::string, std::string> _headersMap;

		void parseHeader(const std::string s, size_t size);

	public:
		RequestHeader();
		RequestHeader(std::string buffer, size_t size);
		~RequestHeader();

		std::map<std::string, std::string> getHeaders() const;
		std::string getHost() const;
		std::string getMethod() const;
		std::string	getBody() const;
		std::string getPath() const;
		std::string getQueryString() const;
		std::string getAccept() const;
		std::string getRedirection() const;
};

#endif
