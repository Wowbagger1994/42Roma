/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_end2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:23:03 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 19:43:07 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexer_tk_id_chr(const int *nb, t_token *target)
{
	if (lexer_id_cmp(target, (int *)nb) == 0)
		return (1);
	return (0);
}

int	lexer_tk_notbeside(t_token *curr, t_token *next, int *forbid, int self)
{
	if ((self && next->id == curr->id)
		|| (forbid && lexer_tk_id_chr(forbid, next)))
		return (0);
	return (1);
}

int	lexer_forbidden_start(t_list *tk_head)
{
	const int	*forbidden = (int	[]){PIPE, OR_IF, AND_IF, RBRACE, -1};

	if (lexer_tk_id_chr(forbidden, tk_head->content))
		return (((t_token *)tk_head->content)->id);
	return (0);
}

int	lexer_forbidden_combo(t_list *tk_head)
{
	const int	*forbidden = (int	[]){PIPE, OR_IF, AND_IF, RBRACE,
		LBRACE, LESS, DLESS, GREAT, DGREAT, -1};
	const int	*matter = (int	[]){LESS, DLESS, GREAT, DGREAT, -1};

	while (tk_head)
	{
		if (lexer_tk_id_chr(matter, tk_head->content))
		{
			if (tk_head->next \
					&& lexer_tk_id_chr(forbidden, tk_head->next->content))
				return (((t_token *)tk_head->next->content)->id);
		}
		tk_head = tk_head->next;
	}
	return (0);
}
