NAME = ft_container

SRCS =  main.cpp \
		tests.cpp \
		tests_utility.cpp \
		tests_vector.cpp \
		tests_stack.cpp \
		tests_map.cpp \
		tests_set.cpp \
		rb_tree.cpp


INCLUDES = .

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I$(INCLUDES)

all : $(NAME)

leaks : $(NAME)
		leaks --atExit -- ./$(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all
