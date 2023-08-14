/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand_assist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:30:50 by charmstr          #+#    #+#             */
/*   Updated: 2022/06/14 01:31:06 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skim_empty_tokens(t_list **tokens)
{
	t_list	*del_me;

	while (*tokens)
	{
		if (!ft_strlen(((t_token *)((*tokens)->content))->str))
		{
			del_me = *tokens;
			*tokens = (*tokens)->next;
			del_token((t_token *)(del_me->content));
			free(del_me);
		}
		else
			tokens = &(*tokens)->next;
	}
}
