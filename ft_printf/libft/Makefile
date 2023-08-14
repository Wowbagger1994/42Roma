# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2022/01/20 17:14:08 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR		= ./


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
RM		= /bin/rm -f

SRCDIR	= ./

NAME	= $(DIR)/libft.a

INCLUDE	= libft.h
SRCS	= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_putunsignednbr_fd.c\
			ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_split.c
OBJS	= $(addprefix $(DIR)/, $(SRCS:.c=.o))
BONUS_S	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

BONUS_O	= $(addprefix $(DIR)/, $(BONUS_S:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			@$(LIB1) $(NAME) $(OBJS)

bonus:		$(NAME) $(BONUS_O)
			@$(LIB1) $(NAME) $(BONUS_O)

.c.o:
			@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
