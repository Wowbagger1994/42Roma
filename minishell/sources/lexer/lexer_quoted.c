/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quoted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:36:05 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 03:03:24 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexer_quoted_double(const char *input, char c,
	int *j, t_token *token)
{
	while (input[*j])
	{
		if (!ft_strappend(&(token->str), input[*j]))
			return (0);
		if (!token->esc_next && input[*j] == c)
		{
			(*j)++;
			token->open_quote = 0;
			return (lexer_find_token(input, j, token));
		}
		token->esc_next = 0;
		(*j)++;
	}
	return (1);
}

static int	lexer_quoted_single(const char *input, char c,
		int *j, t_token *token)
{
	while (input[*j])
	{
		if (!ft_strappend(&(token->str), input[*j]))
			return (0);
		if (input[*j] == c)
		{
			(*j)++;
			token->open_quote = 0;
			return (lexer_find_token(input, j, token));
		}
		(*j)++;
	}
	return (1);
}

int	lexer_quoted(const char *input, int *j, t_token *token)
{
	char	c;

	c = input[*j];
	if (!ft_strappend(&(token->str), c))
		return (0);
	(*j)++;
	token->open_quote = 1;
	if (c == '\'')
	{
		token->id = S_QUOTE;
		return (lexer_quoted_single(input, c, j, token));
	}
	else
	{
		token->id = D_QUOTE;
		return (lexer_quoted_double(input, c, j, token));
	}
}
