/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:54:24 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 03:43:07 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H

# include "minishell.h"
# include <sys/types.h>
# include <sys/stat.h>

void			exe_root(t_btree *ast, t_control *control);

int				exe_semi(t_btree *ast, t_control *control);
int				exe_and(t_btree *ast, t_control *control);
int				exe_or(t_btree *ast, t_control *control);
int				exe_cmd(t_btree *ast, t_control *control);
int				exe_subshell(t_btree *ast, t_control *control);
int				exe_pipe(t_btree *ast, t_control *control);

int				exe_binary(t_simple_cmd *cmd, t_control *control);
int				exe_search_path(char *argv0, t_control *ctrl, char **bnry_pth);

int				exe_simple_cmd_root(t_token *token, t_control *control);

int				exe_perform_indirections(t_arrow *arrow, t_control *control);
int				exe_perform_arrow(t_simple_cmd *cmd, t_control *control);
int				exe_cancel_arrows(t_control *control);
int				exe_redirection_heredoc(t_arrow *arrow, t_control *control);

int				list_to_cmd_root(t_token *token_node);
void			free_t_simple_cmd(void *void_cmd);

int				list_to_cmd_fill_redirections_fields(t_simple_cmd *cmd,
					t_list *tokens);
void			free_t_arrow(void *void_arrow);

int				word_expand_root(t_list **tokens, t_control *control);
void			word_expand_replace(t_list ***tokens, t_list *expanded);

void			skim_empty_tokens(t_list **tokens);

int				parameter_expansion_root(t_list *token, t_control *control,
					int filename);

void			reset_t_expansion(t_expansion *exp, int is_filename,
					t_control *control);
int				parameter_expansion2(t_list **token, char **var,
					t_expansion *exp);

int				field_splitting_root(t_list **token, char *var,
					t_expansion *exp);

int				tild_expansion_root(t_list *env, char **str);
int				tild_expand_try(char **str, char *home_env, int *i);
int				is_tild_expandable(char *str, int i);

int				expand_tild_in_assignement(char **str, char *home_env,
					int i, int start);

int				pathname_expansion_root(t_list **tokens, int is_filename);

t_list			*split_path_root(char *path_to_split);
void			path_set_quoted(char c, char *quoted);

int				add_path_part(char *str, t_list **path_parts, char quoted);
void			delete_path_part_link(void *content);

int				path_part_unquoting(t_path_part *new, char *str);

int				pathname_matching_root(t_path_exp *tool, t_list *path_parts);

int				pathname_matched_add_to_list(t_path_exp *tool, char *path);
int				pathname_matching_closedir_return(DIR *dir_p, int ret);

int				match_path_part_root(t_list *path_parts, char *ref);

void			quote_removal(t_token *token);

void			ft_errno_exit(void);

#endif
