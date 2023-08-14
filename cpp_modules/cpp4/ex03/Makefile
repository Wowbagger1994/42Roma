# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 17:18:31 by ebraho            #+#    #+#              #
#    Updated: 2022/08/10 22:02:34 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interfaceRecap

SRCS = main.cpp \
	AMateria.cpp \
	Ice.cpp \
	Cure.cpp \
	MateriaSource.cpp \
	Character.cpp

INCLUDES = .

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
