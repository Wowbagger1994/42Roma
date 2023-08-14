# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 11:13:12 by ebraho            #+#    #+#              #
#    Updated: 2022/03/27 16:58:20 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavTrap

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp

INCLUDES = ScavTrap.hpp

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
