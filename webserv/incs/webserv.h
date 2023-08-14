#ifndef WEBSERV_H
# define WEBSERV_H

// Colors
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define MAGENTA "\e[0;35m"
# define CYAN "\e[0;36m"
# define RESET "\e[0m"

# define MAX_EVENTS 1024
# define DEFAULT_ERROR_PATH "errors/error_500.html"
# define PYTHON3PATH "/usr/local/bin/python3"
# define AUTOINDEXPATH "./utils/generate_directory_index.py"

# include <cstdlib>
# include <iomanip>
# include <ctype.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <sys/event.h>
# include <sys/stat.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <stdlib.h>
# include <ctime>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <map>
# include <algorithm>
# include "ConfigurationRoute.hpp"
# include "Configuration.hpp"
# include "OpenSocketException.hpp"
# include "Server.hpp"
# include "Clients.hpp"
# include "ConfigurationFile.hpp"
# include "ServerExceptions.hpp"
# include "RequestHeader.hpp"
# include "ResponseHeader.hpp"

#endif
