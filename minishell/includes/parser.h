/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:45:11 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 03:33:44 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_btree			*parser_root(t_list *tokens, t_control *control);

int				parser_is_cmd_start(int tkid);
int				parser_cmd(t_list **tklst, t_btree **new);

int				token_id(t_token *token);
int				tklst_id(t_list *tklst);
int				btree_id(t_btree *node);
int				parser_do_subtree(int tkid);
int				tkcmp_braces(t_token *token);

void			del_ast(t_btree **node);
void			ast_add(t_btree **ast, t_btree *add);
void			parser_pipe_priority(t_btree **ast);

#endif
