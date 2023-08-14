/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:36:51 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:43:45 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	quote_removal_doubly_quoted_part(char *str, int i,
				t_no_unquote *no);

static int	quote_removal_skip_protected_part(char *str, int *i,
		t_no_unquote *no)
{
	if (!str[*i])
		return (0);
	while (str[*i] && *i < no->end)
		(*i)++;
	if (!str[*i])
		return (0);
	return (1);
}

static int	quote_removal_eat_char(char *str, int *i, t_no_unquote *no)
{
	if (!str[*i])
		return (0);
	ft_memmove(str + *i, str + *i + 1, ft_strlen(str + *i));
	no->end--;
	no->start--;
	if (*i == no->start)
	{
		return (quote_removal_skip_protected_part(str, i, no));
	}
	return (1);
}

static void	quote_removal_unquoted_part(char *str, int i, t_no_unquote *no)
{
	while (str[i])
	{
		if (i == no->start)
			if (!quote_removal_skip_protected_part(str, &i, no))
				return ;
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (str[i] == '\'')
			{
				if (!quote_removal_eat_char(str, &i, no))
					return ;
				while (str[i] && str[i] != '\'')
					i++;
				if (!quote_removal_eat_char(str, &i, no))
					return ;
			}
			else
				return (quote_removal_doubly_quoted_part(str, i, no));
		}
		if (str[i] && str[i] == '\\')
			if (!quote_removal_eat_char(str, &i, no))
				return ;
		i++;
	}
}

static void	quote_removal_doubly_quoted_part(char *str, int i, t_no_unquote *no)
{
	if (!quote_removal_eat_char(str, &i, no))
		return ;
	while (str[i])
	{
		if (i == no->start)
			if (!quote_removal_skip_protected_part(str, &i, no))
				return ;
		if (str[i] && str[i] == '\"')
		{
			if (!quote_removal_eat_char(str, &i, no))
				return ;
			return (quote_removal_unquoted_part(str, i, no));
		}
		if (str[i] == '\\' && str[i + 1] && (str[i + 1] == '\\' \
				|| str[i + 1] == '\"' || str[i + 1] == '$' \
				|| str[i + 1] == '\n' || str[i + 1] == '`'))
			if (!quote_removal_eat_char(str, &i, no))
				return ;
		i++;
	}
}

void	quote_removal(t_token *token)
{
	t_no_unquote	no;

	if (token->unquote_protected == 1)
	{
		no.start = token->protect_s;
		no.end = token->protect_e;
	}
	else
	{
		no.start = -1;
		no.end = -1;
	}
	quote_removal_unquoted_part(token->str, 0, &no);
}
