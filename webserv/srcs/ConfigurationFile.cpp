# include "ConfigurationFile.hpp"

ConfigurationFile::ConfigurationFile(std::string configPath) : _file(configPath)
{
	try
	{
		std::stringstream buffer;
		buffer << _file.rdbuf();
		if(buffer.fail()){
			std::cerr << RED << "Error: Invalid configuration path " << configPath << RESET << std::endl;
			exit(1);
		}
		_fileContent = buffer.str();
		_stringConfigurations = splitConfigurations(_fileContent);
		std::vector<std::string>::iterator it = _stringConfigurations.begin();
		for ( ; it != _stringConfigurations.end(); it++)
			_configuarations.push_back(Configuration(*it));
		setMapConfigs();
		std::cout << GREEN << "Parsed configuration: " << BLUE << configPath << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: Parsing configuration file is gone wrong" << RESET << std::endl;
		exit(1);
	}
}

ConfigurationFile::~ConfigurationFile()
{
}

std::vector<std::string> ConfigurationFile::splitConfigurations(std::string content)
{
	std::vector<std::string> configs;
	std::string::size_type start;
	std::string::size_type end = 0;

	while (content.find('}', 0) != std::string::npos)
	{
		start = content.find('{', 0);
		end = content.find('}', 0);
		while (content[end - 1] != '\n')
			end = content.find('}', end + 1);
		if(end != std::string::npos)
			configs.push_back(content.substr(start + 2, end - 2));
		content = content.substr(end + 2);
	}

	return configs;
}

Configuration ConfigurationFile::getConfig(std::string hostPort, std::string serverName)
{
	std::vector<Configuration>::iterator it = _mapConfigs[hostPort].begin();
	Configuration defaultConfig;
	for ( ; it != _mapConfigs[hostPort].end(); it++)
	{
		if (it->getServerName().empty())
			defaultConfig = *it;
		if (it->getServerName() == serverName)
			return *it;
	}
	return defaultConfig;
}

std::vector<Configuration> ConfigurationFile::getConfigs()
{
	return _configuarations;
}

void	ConfigurationFile::setMapConfigs()
{
	std::vector<Configuration>::iterator it1 = _configuarations.begin();
	for ( ; it1 != _configuarations.end(); it1++)
		_mapConfigs[(*it1).getHostPort()].push_back(*it1);
}

std::map<std::string, std::vector<Configuration> > ConfigurationFile::getMapConfigs()
{
	return _mapConfigs;
}
