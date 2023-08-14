/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:47:40 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:38:08 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parser_is_cmd_param(int tkid)
{
	if (tkid == -1)
		return (0);
	if (tkid == TOKEN || tkid == D_QUOTE || tkid == S_QUOTE
		|| tkid == LESS || tkid == DLESS || tkid == GREAT || tkid == DGREAT
		|| tkid == AND)
		return (1);
	return (0);
}

static int	parser_cmdlst(t_list **args, t_list **tklst)
{
	t_list	*tmp;

	tmp = ft_lstnew((*tklst)->content);
	if (!(tmp))
		return (0);
	ft_lstadd_back(args, tmp);
	*tklst = (*tklst)->next;
	if (*tklst != NULL)
		tmp = ft_lstnew((*tklst)->content);
	while (*tklst && parser_is_cmd_param(tklst_id(*tklst)) && tmp)
	{
		ft_lstadd_back(args, tmp);
		*tklst = (*tklst)->next;
		if (*tklst != NULL)
			tmp = ft_lstnew((*tklst)->content);
	}
	if (!tmp)
	{
		ft_lstclear(args, NULL);
		return (0);
	}
	return (1);
}

int	parser_is_cmd_start(int tkid)
{
	if (tkid == -1)
		return (0);
	if (tkid == TOKEN || tkid == D_QUOTE || tkid == S_QUOTE
		|| tkid == LESS || tkid == DLESS || tkid == GREAT || tkid == DGREAT
		|| tkid == AND)
		return (1);
	return (0);
}

int	parser_cmd(t_list **tklst, t_btree **new)
{
	*new = btree_new(NULL);
	if (!(*new))
		return (-1);
	(*new)->item = lexer_init_token();
	if (!((*new)->item))
	{
		ft_free((void **)new);
		return (-1);
	}
	((t_token *)((*new)->item))->id = LIST;
	if (!parser_cmdlst((t_list **)&((t_token *)((*new)->item))->str, tklst))
	{
		ft_free((void **)&(*new)->item);
		ft_free((void **)new);
		return (-1);
	}
	return (1);
}
