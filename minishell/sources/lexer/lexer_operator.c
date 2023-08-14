/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:36:31 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 03:03:04 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexer_operator2(const char *input, int *j, t_token *token)
{
	char	c;

	c = input[*j];
	if (!ft_strappend(&(token->str), c))
		return (0);
	(*j)++;
	if (input[*j] == c)
	{
		token->id++;
		(*j)++;
		if (!ft_strappend(&(token->str), c))
			return (0);
	}
	return (1);
}

static void	lexer_set_operator_id(t_token *token, char c)
{
	int			i;
	char		(*op_ids)[2];

	op_ids = (char [][2]){{'(', LBRACE}, {')', RBRACE},
	{'|', PIPE}, {'&', AND}, {'<', LESS}, {'>', GREAT}, {0, 0}};
	i = -1;
	while (op_ids[++i][0])
		if (op_ids[i][0] == c)
			token->id = op_ids[i][1];
}

int	lexer_operator(const char *input, int *j, t_token *token)
{
	if (token->str)
		return (1);
	lexer_set_operator_id(token, input[*j]);
	if (ft_strchr("();", input[*j]))
	{
		(*j)++;
		token->str = ft_strdup((char [2]){input[*j - 1], '\0'});
		if (!(token->str))
			return (0);
		return (1);
	}
	else if (ft_strchr("<>&|", input[*j]))
		return (lexer_operator2(input, j, token));
	return (0);
}
