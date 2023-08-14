# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 01:57:12 by ebraho            #+#    #+#              #
#    Updated: 2022/03/21 01:57:13 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRCS =  main.cpp \
		Zombie.cpp \
		randomChump.cpp \
		newZombie.cpp \

INCLUDES = Zombie.hpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o ${NAME} $(SRCS) -I$(INCLUDES)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
