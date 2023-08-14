# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 12:24:39 by ebraho            #+#    #+#              #
#    Updated: 2022/08/10 20:35:01 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS =  main.cpp \
		PhoneBook.cpp

INCLUDES = Contact.hpp \
		PhoneBook.hpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o ${NAME} $(SRCS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
