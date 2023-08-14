# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 12:36:07 by ebraho            #+#    #+#              #
#    Updated: 2022/02/13 13:23:10 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
FLAGS  = -Wall -Wextra -Werror

NAME_CLIENT = client
NAME_SERVER = server

INCLUDES = -I./includes
INCLUDES_BONUS = -I./includes_bonus

SRCS_CLIENT = srcs/client.c \
		srcs/utils.c

SRCS_SERVER = srcs/server.c \
		srcs/utils.c

SRCS_CLIENT_BONUS = srcs_bonus/client_bonus.c \
		srcs_bonus/utils_bonus.c

SRCS_SERVER_BONUS = srcs_bonus/server_bonus.c \
		srcs_bonus/utils_bonus.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME_CLIENT) $(OBJS_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME_SERVER) $(OBJS_SERVER)

bonus: $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	$(CC) $(FLAGS) $(INCLUDES_BONUS) -o $(NAME_CLIENT) $(OBJS_CLIENT_BONUS)
	$(CC) $(FLAGS) $(INCLUDES_BONUS) -o $(NAME_SERVER) $(OBJS_SERVER_BONUS)

clean:
	rm -rf $(OBJS_CLIENT)
	rm -rf $(OBJS_SERVER)
	rm -rf $(OBJS_CLIENT_BONUS)
	rm -rf $(OBJS_SERVER_BONUS)

fclean:
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)
	make clean

re: fclean
	$(MAKE) all

.PHONY: re, fclean, clean
