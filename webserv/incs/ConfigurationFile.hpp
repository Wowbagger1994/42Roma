#ifndef CONFIGURATION_FILE_HPP
# define CONFIGURATION_FILE_HPP

# include "webserv.h"

# define DEFAULT_PATH "configuration_file.conf"

class ConfigurationFile
{
private:
	std::ifstream _file;
	std::string	_fileContent;
	std::vector<std::string> _stringConfigurations;
	std::vector<Configuration> _configuarations;
	std::map<std::string, std::vector<Configuration> > _mapConfigs;

	void	setMapConfigs();
	std::vector<std::string> splitConfigurations(std::string buffer);

public:
	ConfigurationFile(std::string configPath);
	~ConfigurationFile();
	Configuration getConfig(std::string port, std::string serverName);
	std::vector<Configuration> getConfigs();
	std::map<std::string, std::vector<Configuration> > getMapConfigs();
};

#endif
