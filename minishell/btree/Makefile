# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 17:32:03 by pcoletta          #+#    #+#              #
#    Updated: 2022/06/21 12:34:12 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btree
SRCS = btree_new.c btree_add.c btree_clear.c btree_delone.c btree_depth.c btree_find.c\
		btree_apply_bfs.c btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I btree.h


$(NAME): $(OBJS)
	make -C ../libft
	ar -crs $(NAME).a $(OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	make -C ../libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C ../libft fclean
	rm -rf $(NAME).a

re: fclean all
