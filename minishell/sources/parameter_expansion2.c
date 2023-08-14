/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:30:40 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:32:39 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	need_to_field_split2(char **str, t_expansion *exp)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strtrim(*str, exp->ifs);
	if (!(*str))
	{
		free(tmp);
		return (2);
	}
	free(tmp);
	if (-1 != ft_stristr(*str, exp->ifs))
		return (1);
	return (0);
}

static int	need_to_field_split1(char **str, t_expansion *exp)
{
	char	*tmp;

	tmp = *str;
	if (exp->quoted || (exp->ifs && !ft_strlen(exp->ifs)))
		return (0);
	if (!exp->ifs)
	{
		*str = ft_strtrim(*str, " \t\n");
		if (!(*str))
		{
			free(tmp);
			return (2);
		}
		free(tmp);
		if (-1 != ft_stristr(*str, " \t\n"))
			return (1);
		return (0);
	}
	else
	{
		return (need_to_field_split2(str, exp));
	}
}

static int	param_exp_no_fsplit(t_list *token, char *var, t_expansion *exp)
{
	char	**ptr_str;

	ptr_str = &((t_token *)token->content)->str;
	((t_token *)token->content)->protect_e = ft_strlen(var) + exp->start;
	if (!ft_strstradd(ptr_str, exp->start, var))
		return (0);
	exp->start += ft_strlen(var);
	return (1);
}

void	reset_t_expansion(t_expansion *exp, int is_filename,
		t_control *control)
{
	exp->start = 0;
	exp->end = 0;
	exp->quoted = 0;
	exp->is_filename = is_filename;
	exp->ifs = env_get("IFS", 3, control->env);
}

int	parameter_expansion2(t_list **token, char **var, t_expansion *exp)
{
	int	field_split;

	((t_token *)(*token)->content)->unquote_protected = 1;
	((t_token *)(*token)->content)->protect_s = exp->start;
	field_split = need_to_field_split1(var, exp);
	if (field_split == 2 || (field_split == 1 && exp->is_filename))
		return (field_split);
	if (!field_split)
	{
		if (!param_exp_no_fsplit(*token, *var, exp))
			return (2);
	}
	else
	{
		if (!field_splitting_root(token, *var, exp))
			return (2);
	}
	return (0);
}
