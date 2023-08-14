# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 03:53:04 by ebraho            #+#    #+#              #
#    Updated: 2022/04/04 16:26:22 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern

SRCS =  main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp

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

re : fclean all
