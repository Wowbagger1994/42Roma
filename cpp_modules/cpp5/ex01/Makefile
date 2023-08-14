# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 03:53:04 by ebraho            #+#    #+#              #
#    Updated: 2022/04/03 02:13:08 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form

SRCS =  main.cpp \
		Bureaucrat.cpp \
		Form.cpp

INCLUDES = -I Form.hpp -I Bureaucrat.hpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) -o ${NAME} $(FLAGS) $(SRCS) $(INCLUDES)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all
