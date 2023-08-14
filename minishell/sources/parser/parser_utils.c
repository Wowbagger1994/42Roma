/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:21:37 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 03:33:46 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_id(t_token *token)
{
	if (!token)
		return (-1);
	return (token->id);
}

int	tklst_id(t_list *tklst)
{
	if (!tklst)
		return (-1);
	return (token_id(tklst->content));
}

int	btree_id(t_btree *node)
{
	if (!node)
		return (-1);
	return (token_id(node->item));
}

int	parser_do_subtree(int tkid)
{
	if (tkid == LBRACE)
		return (1);
	return (0);
}

int	tkcmp_braces(t_token *token)
{
	int	id;

	id = token_id(token);
	if (id == LBRACE || id == RBRACE)
		return (0);
	return (1);
}
