# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 03:53:04 by ebraho            #+#    #+#              #
#    Updated: 2022/08/18 18:12:52 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = formUp

SRCS =  main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp

INCLUDES = -I .

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
	rm -rf Garden_shrubbery
	rm -rf garden_shrubbery

re : fclean all
