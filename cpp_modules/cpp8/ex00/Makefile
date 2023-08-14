# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 01:33:00 by ebraho            #+#    #+#              #
#    Updated: 2022/08/20 23:52:25 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind

SRCS = main.cpp

INCLUDES = easyfind.hpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS) $(TOBJS)
	$(CC) $(FLAGS) -o ${NAME} $(SRCS) -I$(INCLUDES)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
