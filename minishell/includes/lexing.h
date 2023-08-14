/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:03 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:23:46 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

# include "minishell.h"

# define TOKEN 0
# define PIPE 1
# define OR_IF 2
# define AND 3
# define AND_IF 4
# define LBRACE 5
# define RBRACE 6
# define S_QUOTE 7
# define D_QUOTE 8
# define LESS 9
# define DLESS 10
# define GREAT 11
# define DGREAT 12

# define SUBSHELL 13
# define LIST 14
# define CMD 15

t_list	*lexer_root(char *input, t_control *control);
t_token	*lexer_init_token(void);
void	del_token(void *token);

int		lexer_find_token(const char *input, int *j, t_token *token);

int		lexer_operator(const char *input, int *j, t_token *token);

int		lexer_quoted(const char *input, int *j, t_token *token);

int		lexer_just_token(const char *input, int *j, t_token *token);

int		lexer_id_cmp(t_token *token, int *id);
int		lexer_end(t_list *token_head, t_control *control);

int		lexer_forbidden_start(t_list *tk_head);
int		lexer_forbidden_start_no_exceptions(t_list *token);
int		lexer_tk_notbeside(t_token *curr, t_token *next, int *forbid, int self);
int		lexer_forbidden_combo(t_list *tk_head);

#endif
