/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_splitting_root.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:46:26 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 02:56:29 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	field_splitting_assist(t_list **tok, char *str)
{
	t_list	*new_link;
	t_token	*new_token;

	new_token = lexer_init_token();
	if (!(new_token))
		return (0);
	new_token->str = ft_strdup(str);
	if (!(new_token->str))
	{
		free(new_token);
		return (0);
	}
	new_token->id = TOKEN;
	new_token->unquote_protected = 1;
	new_token->protect_s = 0;
	new_token->protect_e = ft_strlen(new_token->str);
	new_link = ft_lstnew(new_token);
	if (!(new_link))
	{
		del_token(new_token);
		return (0);
	}
	ft_lstadd_front(tok, new_link);
	return (1);
}

static int	field_splitting(t_list **tok, t_expansion *exp,
	char **array, char *str2)
{
	char	**str;
	int		i;

	i = 1;
	str = &((t_token *)(*tok)->content)->str;
	*str = ft_strjoin_free(*str, array[0], 1);
	if (array[0] && !(*str))
		return (0);
	while (array[i])
	{
		tok = &(*tok)->next;
		if (!(field_splitting_assist(tok, array[i])))
			return (0);
		i++;
	}
	str = &((t_token *)(*tok)->content)->str;
	exp->start = ft_strlen(*str);
	*str = ft_strjoin_free(*str, str2, 1);
	if (!(*str))
		return (0);
	return (1);
}

static int	field_splitting_root_assist(t_list **token, t_expansion *exp,
	char *var, char *str2)
{
	char	**array;

	if (!exp->ifs)
	{
		array = ft_split_whitespaces(var, " \n\t");
		if (!(array))
			return (0);
	}
	else
	{
		array = ft_split_whitespaces(var, exp->ifs);
		if (!(array))
			return (0);
	}
	((t_token *)(*token)->content)->protect_e = exp->start + \
				ft_strlen(array[0]);
	if (!field_splitting(token, exp, array, str2))
	{
		ft_array_free(array, ft_array_len(array));
		return (0);
	}
	ft_array_free(array, ft_array_len(array));
	return (1);
}

int	field_splitting_root(t_list **token, char *var, t_expansion *exp)
{
	char	*str1;
	char	*str2;

	str1 = ((t_token *)(*token)->content)->str;
	str2 = ft_substr(str1, exp->start, ft_strlen(str1) + exp->start);
	if (!(str2))
		return (0);
	str1[exp->start] = '\0';
	if (!field_splitting_root_assist(token, exp, var, str2))
	{
		free(str2);
		return (0);
	}
	free(str2);
	return (1);
}
