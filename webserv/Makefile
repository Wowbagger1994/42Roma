NAME = webserv

S		= srcs/
O		= objs/
I		= incs/

SRCS =  Clients.cpp \
		Configuration.cpp \
		ConfigurationFile.cpp \
		ConfigurationRoute.cpp \
		RequestHeader.cpp \
		ResponseHeader.cpp \
		Server.cpp \
		webserv.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g -I$I

SRCS	:= $(foreach file,$(SRCS),$S$(file))
OBJS	= $(SRCS:$S%=$O%.o)
DEPS	= $(SRCS:$S%=$D%.d)

all : $(NAME)

$O:
	@mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	@echo "Compiling $^: "
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "✓"

$(NAME): $(OBJS)
	@echo "Assembling $(NAME)"
	@$(CC) $^ -o $@
	@mkdir -p uploads

clean :
	rm -rf $(O)
	rm -rf uploads
	find . -name "*.index.html" -type f -delete

fclean : clean
	rm -rf ${NAME}

re : fclean all
