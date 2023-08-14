CC      = gcc
FLAGS  = -Wall -Wextra -Werror

NAME = philo/philo
NAME_BONUS = philo_bonus/philo_bonus

INCLUDES = -I./philo/includes
INCLUDES_BONUS = -I./philos_bnous/includes_bonus

SRCS = philo/srcs/main.c \
		philo/srcs/utils.c \
		philo/srcs/initializer.c \
		philo/srcs/printers.c \
		philo/srcs/threads.c

SRCS_BONUS = philo_bonus/srcs/main.c \
		philo_bonus/srcs/utils.c \
		philo_bonus/srcs/initializer.c \
		philo_bonus/srcs/printers.c 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(CC) $(FLAGS) $(INCLUDES_BONUS) -o $(NAME_BONUS) $(OBJS_BONUS)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean:
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make clean

re: fclean
	$(MAKE) all

.PHONY: re, fclean, clean
