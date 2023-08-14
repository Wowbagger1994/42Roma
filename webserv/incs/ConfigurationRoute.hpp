#ifndef CONFIGURATION_ROUTE_HPP
# define CONFIGURATION_ROUTE_HPP

# include "webserv.h"

class ConfigurationRoute
{
	private:
		std::string _path;
		std::map<std::string, std::string> _map;
		void SetMap(std::string stringConfig);
	public:
		ConfigurationRoute();
		ConfigurationRoute(std::string stringConfig, std::string path);
		~ConfigurationRoute();
		std::string getPath();
		std::string getRoot();
		std::vector<std::string> getCgiPass();
		std::string getUploadPath();
		bool getAutoindex();
		std::string getMethods();
		std::string getIndex();
};

#endif
