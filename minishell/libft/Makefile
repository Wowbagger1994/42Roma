# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 17:32:03 by pcoletta          #+#    #+#              #
#    Updated: 2022/06/21 12:09:03 by ebraho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
SRCS = ft_bzero.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c\
		ft_strnstr.c ft_strrchr.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_memcmp.c ft_striteri.c ft_strmapi.c ft_substr.c ft_calloc.c\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlcpy.c ft_stristr.c\
		ft_array_free.c ft_array_len.c ft_dlstclear.c ft_dlstclearback_addr.c ft_dlstnew.c\
		ft_free.c ft_isonly.c ft_isonly_ft.c ft_lstadd_back.c ft_lstadd_front.c\
		ft_lstclear.c ft_lstfind.c ft_lstlast.c ft_lstnew.c ft_lstremove_if.c\
		ft_lstsize.c ft_memalloc.c ft_split_whitespaces.c ft_strappend.c ft_strcdel.c\
		ft_strcmp.c ft_strichr.c ft_strjoin_free.c ft_strstradd.c ft_lstnew.c\
		ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_dlstdelone.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft.h


$(NAME): $(OBJS)
	ar -crs $(NAME).a $(OBJS)

bonus: ${OBJS}
	ar -crs $(NAME).a $(OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME).a

re: fclean all
