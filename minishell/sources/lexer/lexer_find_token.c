/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_find_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:44:29 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/13 17:21:33 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer_find_token(const char *input, int *j, t_token *token)
{
	if (!input[*j])
		return (1);
	if (ft_strchr("\"\'", input[*j]))
		return (lexer_quoted(input, j, token));
	else if (ft_strchr("&<>()|;", input[*j]))
		return (lexer_operator(input, j, token));
	return (lexer_just_token(input, j, token));
}
