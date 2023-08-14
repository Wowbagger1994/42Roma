#ifndef CONFIGURATION_HPP
# define CONFIGURATION_HPP

# include "webserv.h"

class ConfigurationRoute;

class Configuration
{
	private:
		std::map<std::string, std::string> _map;
		std::vector<std::string>	_methods;
		std::map<std::string, ConfigurationRoute> _configsRoute;

		void setMap(std::string configurationString);
		void setMethods();
		void setConfigsRoute();
	public:
		Configuration();
		Configuration(std::string configurationString);
		~Configuration();
		std::string getHostPort();
		std::string	getHost();
		unsigned int getPort();
		std::map<std::string, ConfigurationRoute> getConfigsRoute() const;
		std::string	getServerName();
		size_t getLimitSizeBody();
		int getRedirectionCode();
		std::string getRedirectionUrl();
		std::string getErrorPath(std::string code) const;
		bool checkMethod(std::string method);
		bool isEmpty();
};

#endif
