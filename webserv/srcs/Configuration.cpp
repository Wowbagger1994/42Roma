# include "Configuration.hpp"

Configuration::Configuration()
{
}

Configuration::Configuration(std::string configurationString)
{
	setMap(configurationString);
	setConfigsRoute();
	setMethods();
}

Configuration::~Configuration()
{
}

void Configuration::setMap(std::string configurationString)
{
	std::string::size_type start;
	std::string::size_type end = 0;

	while (end < configurationString.size())
	{
		start = configurationString.find('=', 0);
		if (configurationString.substr(1, start - 1) == "routes")
		{
			end = configurationString.find('}', 0);
			while (configurationString.find('}', end + 1) != std::string::npos)
				end = configurationString.find('}', end + 1);
			if(end != std::string::npos)
				_map.insert(std::make_pair<std::string, std::string>(
					configurationString.substr(1, start - 1),
					configurationString.substr(start + 1, end - start)));
			configurationString = configurationString.substr(end, 0);
			if (end != std::string::npos)
				end = configurationString.find('\n', end);
			else
				end = configurationString.find('\n', 0);
		}
		else
		{
			end = configurationString.find('\n', 0);
			if(end != std::string::npos)
				_map.insert(std::make_pair<std::string, std::string>(
					configurationString.substr(1, start - 1),
					configurationString.substr(start + 1, end - start - 1)));
			configurationString = configurationString.substr(end + 1);
		}
	}
	start = configurationString.find('=', 0);
	end = configurationString.find('\0', 0);
	if(start != std::string::npos)
		_map.insert(std::make_pair<std::string, std::string>(
			configurationString.substr(1, start - 1),
			configurationString.substr(start + 1, end - 1)));
	//for (std::map<std::string, std::string>::iterator i = _map.begin() ; i != _map.end(); i++)
	//	std::cout << GREEN << "first: " << RESET << std::left << std::setw(20) << std::setfill(' ') << (*i).first << GREEN << " second: " << RESET << (*i).second << std::endl;
}

void Configuration::setConfigsRoute() {
	if (_map.find("routes") == _map.end())
		return;
	std::string strRoutes = _map.at("routes");
	std::string::size_type start;
	std::string::size_type end = 0;
	std::string::size_type last = 0;

	do {
		start = strRoutes.find('{', 0);
		end = strRoutes.find('}', 0);
		last = strRoutes.find('/', last);
		_configsRoute.insert(std::make_pair<std::string, ConfigurationRoute>(
			strRoutes.substr(last, strRoutes.find('\n', last) - last),
			ConfigurationRoute(strRoutes.substr(start, end - start + 1), strRoutes.substr(last, strRoutes.find('\n', last) - last))));
		strRoutes = strRoutes.substr(end + 1);
		end = strRoutes.find('}', 0);
	} while (end < strRoutes.size());
}

std::string Configuration::getHostPort()
{
	try
	{
		return _map.at("host/port");
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: Missing host/port attribute in the configuration file" << RESET << std::endl;
		exit(1);
	}

}

std::string Configuration::getHost()
{
	std::string hp = getHostPort();
	return hp.substr(0,  hp.find(':', 0));
}

unsigned int Configuration::getPort()
{
	std::string hp = getHostPort();
	return std::atoi(hp.substr(hp.find(':', 0) + 1, hp.length() - hp.find(':', 0) - 1).c_str());
}

std::string Configuration::getServerName()
{
	return _map["server_name"];
}

size_t Configuration::getLimitSizeBody()
{
	std::string limitSize = _map["max_body_size"].c_str();
	if (limitSize.empty())
		return LLONG_MAX;
	return std::atoi(limitSize.c_str());
}

int Configuration::getRedirectionCode()
{
	if (!_map["return"].empty())
		return std::atoi(_map["return"].substr(0, 3).c_str());
	return 0;
}

std::string Configuration::getRedirectionUrl()
{
	std::string redirection = _map["return"];
	if (!redirection.empty())
	{
		int start = redirection.find(' ', 0) + 1;
		return _map["return"].substr(start, redirection.size() - start);
	}
	return std::string();
}

std::string Configuration::getErrorPath(std::string code) const
{
	try
	{
		return _map.at(code);
	}
	catch(const std::exception& e)
	{
		return "errors/error_500.html";
	}

}

std::map<std::string, ConfigurationRoute> Configuration::getConfigsRoute() const{
	return _configsRoute;
}

void Configuration::setMethods(){
	std::string::size_type start;
	std::string::size_type end = 0;

	while (end < _map["methods"].size())
	{
		start = 0;
		end = _map["methods"].find(' ', 0);
		if(end != std::string::npos)
		{
			_methods.push_back(_map["methods"].substr(start, end));
			_map["methods"] = _map["methods"].substr(end + 1);
		}
	}
	_methods.push_back(_map["methods"].substr(0, _map["methods"].length()));
}

bool Configuration::checkMethod(std::string method)
{
	return _methods.end() != std::find(_methods.begin(), _methods.end(), method);
}

bool Configuration::isEmpty()
{
	return _map.size() == 0;
}
