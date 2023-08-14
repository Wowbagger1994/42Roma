# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 18:45:42 by pcoletta          #+#    #+#              #
#    Updated: 2022/06/21 16:43:34 by pcoletta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS_FILE_NAMES = main\
			utils/minishell_utils\
			lexer/lexer_root\
			lexer/lexer_find_token\
			lexer/lexer_quoted\
			lexer/lexer_operator\
			lexer/lexer_just_token\
			lexer/lexer_end\
			lexer/lexer_end2\
			builtins/builtin_env\
			builtins/builtin_unset\
			builtins/builtin_echo\
			builtins/builtin_export\
			builtins/builtin_export_no_arg\
			builtins/builtin_cd\
			builtins/builtin_pwd\
			builtins/builtin_exit\
			input_root\
			reset_prompts\
			termios_utils\
			read_root\
			control_structure\
			parser/parser_root\
			parser/parser_cmd\
			parser/parser_utils\
			parser/parser_ast\
			executor/exe_root\
			executor/exe_ope\
			executor/exe_pipe\
			executor/exe_simple_cmd_root\
			executor/exe_perform_arrow\
			executor/exe_heredoc\
			executor/exe_binary\
			executor/exe_binary_search\
			word_expand_root\
			word_expand_assist\
			parameter_expansion_root\
			parameter_expansion2\
			field_splitting_root\
			pathname_expansion_root\
			tild_expansion_root\
			tild_expansion_assist\
			split_path_root\
			split_path2\
			split_path3\
			pathname_matching_root\
			pathname_matching_utils\
			match_path_parts_root\
			list_to_cmd_root\
			list_to_cmd_assist\
			signal_handler\
			quote_removal\
			utils/env_utils1\
			utils/env_utils2\
			utils/error_utils\
			signal_handler_enabler
SRCS = $(addprefix sources/, $(addsuffix .c,$(SRCS_FILE_NAMES)))
OBJS = $(SRCS:.c=.o)
HEADERS = libft/libft.h btree/btree.h includes/ includes/buildin.h includes/exe.h includes/lexing.h includes/minishell.h includes/parser.h includes/structures.h includes/terminfo.h

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror $(addprefix -I,$(HEADERS))

$(NAME): $(OBJS)
	make -C btree
	$(CC) $(CFLAGS) -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include -o $(NAME) $(OBJS) libft/libft.a btree/btree.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I/Users/$(USER)/.brew/opt/readline/include -c $< -o $(<:.c=.o)

clean:
	make -C btree clean
	rm -rf $(OBJS)

fclean: clean
	make -C btree fclean
	rm -rf $(NAME)

re: fclean all
