# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 16:00:46 by ebraho            #+#    #+#              #
#    Updated: 2022/02/07 22:31:04 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc -O2
FLAGS  = -Wall -Wextra -Werror

NAME   = fractol

INCLUDES = -I./includes
INCLUDES_BONUS = -I./includes_bonus

MLX = mlx

SRCS = srcs/main.c \
		srcs/mandelbrot.c \
		srcs/julia.c \
		srcs/hooks.c \
		srcs/utils.c \
		srcs/color.c

SRCS_BONUS = srcs_bonus/main.c \
		srcs_bonus/mandelbrot.c \
		srcs_bonus/julia.c \
		srcs_bonus/fern.c \
		srcs_bonus/hooks.c \
		srcs_bonus/utils.c \
		srcs_bonus/color.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: lib $(NAME)

lib:
	make -C $(MLX)
	cp mlx/libmlx.dylib .

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) -framework OpenGL -framework AppKit $(OBJS) libmlx.dylib

bonus: lib $(OBJS_BONUS)
	$(CC) $(FLAGS) $(INCLUDES_BONUS) -o $(NAME) -framework OpenGL -framework AppKit $(OBJS_BONUS) libmlx.dylib

clean:
	make clean -C $(MLX)
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean:
	rm -f $(NAME)
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	rm -f libmlx.dylib
	make clean -C $(MLX)

re: fclean
	$(MAKE) all

.PHONY: temporary, re, fclean, clean
