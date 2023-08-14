/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tild_expansion_assist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:31:56 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:58:31 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	tild_expand_try_after_column(char **str, char *home_env, int *i)
{
	if (!(*str)[*i + 1])
		return (1);
	(*i)++;
	if (is_tild_expandable(*str, *i))
		return (tild_expand_try(str, home_env, i));
	(*i)--;
	return (1);
}

int	expand_tild_in_assignement(char **str, char *home_env, int i, int start)
{
	int		esc_next;
	char	quoted;

	esc_next = 0;
	quoted = 0;
	while ((*str)[++i])
	{
		if ((i == start + 1) && !tild_expand_try(str, home_env, &i))
			return (0);
		if (!quoted && !esc_next && (*str)[i] == '\\')
		{
			esc_next = 1;
			continue ;
		}
		if (!esc_next && ((*str)[i] == '\'' || (*str)[i] == '"'))
			path_set_quoted((*str)[i], &quoted);
		if (!quoted && !esc_next && (*str)[i] == ':')
		{
			if (!tild_expand_try_after_column(str, home_env, &i))
				return (0);
		}
		esc_next = 0;
	}
	return (1);
}
