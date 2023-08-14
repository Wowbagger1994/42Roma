# include "RequestHeader.hpp"

RequestHeader::RequestHeader() {}

RequestHeader::RequestHeader(std::string buffer, size_t size) {
	parseHeader(buffer, size);
	// for (std::map<std::string, std::string>::iterator it = _headersMap.begin(); it != _headersMap.end(); it++)
	// 	std::cout << YELLOW << "Key: " << RESET << std::left << std::setw(25) << std::setfill(' ') << (*it).first << YELLOW << "Value: " << RESET << (*it).second << "$" << std::endl;
	// std::cout << std::endl << std::endl;
}

RequestHeader::~RequestHeader() {
}

void RequestHeader::parseHeader(const std::string s, size_t size) {
	std::istringstream resp(s);
	std::string header;
	std::string::size_type index;
	size_t n = 2;
	while (std::getline(resp, header) && header != "\r") {
		size_t pos = 0;
		while ((pos = header.find(13)) != std::string::npos)
			header.erase(pos);
		index = header.find(':', 0);
		if(index != std::string::npos)
		{
			std::pair<std::string, std::string> tmp = std::make_pair(header.substr(0, index), header.substr(index + 2));
			if (_headersMap.find("Cookie") != _headersMap.end()
				&& tmp.first == "Cookie")
				_headersMap["Cookie"].append("; " + tmp.second);
			else
				_headersMap.insert(tmp);
		}
		else
			_headersMap.insert(std::make_pair("Method", header));
		n += header.size() + 2;
	}
	if (size > n)
		_headersMap.insert(std::make_pair("Body", s.substr(n, size - n)));
}

std::map<std::string, std::string> RequestHeader::getHeaders() const
{
	return _headersMap;
}

std::string RequestHeader::getHost() const {
	return _headersMap.at("Host").substr(0, _headersMap.at("Host").find(':', 0));
}

std::string RequestHeader::getMethod() const {
	try{
		return _headersMap.at("Method").substr(0, _headersMap.at("Method").find(' ', 0));
	}
	catch(const std::exception& e){
		return std::string();
	}
}

std::string	RequestHeader::getBody() const {
	try{
		return _headersMap.at("Body");
	}
	catch(const std::exception& e){
		return std::string();
	}
}

std::string RequestHeader::getPath() const {
	size_t temp = _headersMap.at("Method").find(' ', 0) + 1;
	std::string fullPath = _headersMap.at("Method").substr(temp, _headersMap.at("Method").find(' ', temp + 1) - temp);
	temp = fullPath.find('?', 0);
	if (temp == std::string::npos)
		return fullPath;
	else
		return fullPath.substr(0, temp);
}

std::string RequestHeader::getQueryString() const {
	size_t temp = _headersMap.at("Method").find(' ', 0) + 1;
	std::string fullPath = _headersMap.at("Method").substr(temp, _headersMap.at("Method").find(' ', temp + 1) - temp);
	temp = fullPath.find('?', 0);
	if (temp == std::string::npos)
		return std::string();
	else
		return fullPath.substr(temp + 1, fullPath.size() - temp);
}
std::string RequestHeader::getAccept() const {
	return _headersMap.at("Accept");
}
