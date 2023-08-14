# include "ConfigurationRoute.hpp"

ConfigurationRoute::ConfigurationRoute()
{
}

ConfigurationRoute::ConfigurationRoute(std::string stringConfig, std::string path) : _path(path) {
	SetMap(stringConfig);
}

ConfigurationRoute::~ConfigurationRoute()
{
}

void ConfigurationRoute::SetMap(std::string stringConfig)
{
	std::string::size_type start;
	std::string::size_type end = 0;
	std::string::size_type i;

	stringConfig = stringConfig.substr(2, stringConfig.size() - 2);
	do {
		i = 0;
		while(isspace(stringConfig[i]))
			i++;
		start = stringConfig.find('=', 0);
		end = stringConfig.find('\n', 0);
		if(end != std::string::npos)
			_map.insert(std::make_pair<std::string, std::string>(
				stringConfig.substr(i, start - i),
				stringConfig.substr(start + 1, end - start - 1)));
		stringConfig = stringConfig.substr(end + 1);
	} while (end < stringConfig.size());
	// for (std::map<std::string, std::string>::iterator i = _map.begin() ; i != _map.end(); i++)
	// 	std::cout << GREEN << "first: " << RESET << std::left << std::setw(20) << std::setfill(' ') << (*i).first << GREEN << " second: " << RESET << (*i).second << std::endl;
}

std::string ConfigurationRoute::getPath() {
	return _path;
}

std::string ConfigurationRoute::getRoot() {
	return _map["root"];
}

std::vector<std::string> ConfigurationRoute::getCgiPass()
{
	std::vector<std::string> cgi;
	int delimiter = _map["cgi_pass"].find(' ');
	cgi.push_back(_map["cgi_pass"].substr(0, delimiter));
	cgi.push_back(_map["cgi_pass"].substr(delimiter + 1, _map["cgi_pass"].size() - delimiter - 1));
	return cgi;
}

std::string ConfigurationRoute::getUploadPath()
{
	std::string uploadPath = _map["upload_directory"];
	if (uploadPath.empty())
		return std::string();
	return uploadPath;
}

bool ConfigurationRoute::getAutoindex(){
	return _map["autoindex"] == "on";
}

std::string ConfigurationRoute::getMethods(){
	return _map["methods"];
}

std::string ConfigurationRoute::getIndex(){
	return _map["index"];
}
