# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 16:50:56 by ebraho            #+#    #+#              #
#    Updated: 2022/02/21 15:56:42 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CHECKER = checker

SRCS =  srcs/main.c \
		srcs/moves_a.c \
		srcs/moves_b.c \
		srcs/moves_ab.c \
		srcs/moves.c \
		srcs/run.c \
		srcs/checkers.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/utils3.c \
		srcs/utils4.c \
		srcs/lis.c \
		srcs/ft_split.c

SRCS_BONUS = srcs_bonus/checker.c \
			srcs_bonus/checkers.c\
			srcs_bonus/ft_split.c \
			srcs_bonus/moves.c \
			srcs_bonus/utils.c \
			srcs_bonus/run.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./include

INCLUDES_BONUS = -I./include_bonus

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o ${NAME} $(INCLUDES) $(SRCS)

all : $(NAME)

bonus : $(OBJS_BONUS)
	$(CC) $(FLAGS) -o ${NAME_CHECKER} $(INCLUDES_BONUS) $(SRCS_BONUS)

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_CHECKER)

re : fclean all
