/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_just_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:37:18 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:20:15 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer_just_token(const char *input, int *j, t_token *token)
{
	while (input[*j] && (token->esc_next || input[*j] != ' '))
	{
		if (!token->esc_next && ft_strchr("\"\'", input[*j]))
			return (lexer_quoted(input, j, token));
		else if (!token->esc_next && ft_strchr("&<>()|;", input[*j]))
			return (1);
		else if (!token->esc_next && input[*j] == '\\')
		{
			token->esc_next = 1;
			if (!ft_strappend(&(token->str), input[*j]))
				return (0);
			(*j)++;
			continue ;
		}
		else if (!ft_strappend(&(token->str), input[*j]))
			return (0);
		token->esc_next = 0;
		(*j)++;
	}
	return (1);
}
