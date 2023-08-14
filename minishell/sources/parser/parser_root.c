/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_root.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:05:01 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 19:01:48 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_btree	*parser_create_ast(t_dlist *dlst, t_list **tklst);

static int	parser_be_subshell(t_btree **new)
{
	t_btree	*tmp;
	t_token	*token;

	tmp = NULL;
	token = ft_memalloc(sizeof(t_token));
	if (!token)
		return (-1);
	token->id = SUBSHELL;
	if ((*new)->item != NULL)
	{
		tmp = btree_new(token);
		if (!tmp)
		{
			ft_free((void **)&token);
			return (-1);
		}
		tmp->left = *new;
		*new = tmp;
	}
	else
		(*new)->item = token;
	return (1);
}

static int	parser_next_subtree(t_dlist **dlst, t_list **tklst, t_btree **new)
{
	*tklst = (*tklst)->next;
	if (!*tklst)
		return (-1);
	(*dlst)->next = ft_dlstnew(NULL);
	if (!((*dlst)->next))
		return (-1);
	(*dlst)->next->previous = *dlst;
	*new = parser_create_ast((*dlst)->next, tklst);
	if (!(*new))
		return (-1);
	if (parser_be_subshell(new) == -1)
		return (-1);
	ft_free((void **)&((*dlst)->next));
	return (0);
}

static int	parser_next_child(t_dlist **dlst, t_list **tklst, t_btree **new)
{
	if (parser_is_cmd_start(tklst_id(*tklst)))
		return (parser_cmd(tklst, new));
	if (parser_do_subtree(token_id((*tklst)->content)))
	{
		if (parser_next_subtree(dlst, tklst, new) == -1)
			return (-1);
	}
	else
	{
		*new = btree_new((*tklst)->content);
		if (!(*new))
			return (-1);
	}
	if (*tklst)
		*tklst = (*tklst)->next;
	return (1);
}

static t_btree	*parser_create_ast(t_dlist *dlst, t_list **tklst)
{
	t_btree		*new;
	int			state;

	dlst->content = btree_new(NULL);
	if (!(dlst->content))
		return (NULL);
	while (*tklst && token_id((*tklst)->content) != RBRACE)
	{
		state = parser_next_child(&dlst, tklst, &new);
		if (state == 1)
			ast_add((t_btree **)&dlst->content, new);
		else if (state == -1)
			return (NULL);
	}
	return (dlst->content);
}

t_btree	*parser_root(t_list *tklst, t_control *control)
{
	t_dlist		*dlst;
	t_btree		*ast;
	t_list		*tkcpy;

	ast = NULL;
	tkcpy = tklst;
	if (!tkcpy)
		return (NULL);
	dlst = ft_memalloc(sizeof(*dlst));
	ast = parser_create_ast(dlst, &tkcpy);
	if (dlst && ast)
	{
		ft_lstremove_if(&tklst, NULL, tkcmp_braces, del_token);
		ft_lstclear(&tklst, NULL);
		ft_dlstclear(&dlst, NULL);
		parser_pipe_priority(&ast);
	}
	else
	{
		control->quit = 1;
		ft_lstclear(&tklst, del_token);
		ft_dlstclearback_addr(&dlst, (void (*)(void **)) & del_ast);
	}
	return (ast);
}
