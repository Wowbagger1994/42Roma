# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:10:27 by ebraho            #+#    #+#              #
#    Updated: 2022/06/23 04:20:17 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRCS =  main.cpp \
		Fixed.cpp \

INCLUDES = Fixed.hpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -I$(INCLUDES) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
