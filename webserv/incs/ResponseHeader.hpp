#ifndef RESPONSE_HEADER_HPP
# define RESPONSE_HEADER_HPP

# include "webserv.h"

int execAutoindex();

class Server;
class RequestHeader;

class ResponseHeader
{
	private:
		Server *_server;
		RequestHeader *_request;
		Configuration *_config;
		std::map<int, std::string> _codeMap;
		std::string _path;
		std::string _content;
		std::string _contentType;
		int _contentLenght;
		std::map<std::string, std::string> _env;
		std::pair<std::string, std::string> _error;

		void setCodeMap();
		void setPath();
		void setContent();
		void setContentType(std::string path, std::string type = "");
		void setEnv();
		char **getEnvAsCstrArray() const;
		std::string executeCgi(const std::vector<std::string>& cgiPas);
		ConfigurationRoute getMatchingRoute(std::string path) const;

	public:
		ResponseHeader(Server *server, RequestHeader *request, Configuration *config);
		ResponseHeader(RequestHeader *request, std::pair<std::string, std::string> error = std::make_pair("500", DEFAULT_ERROR_PATH));
		~ResponseHeader();
		std::string makeResponse(int code) const;
		std::string getResponseCode(int code) const;
		std::string getContentType() const;
		std::string getDate() const;
		std::pair<std::string, std::string> getError() const;
};

#endif
