/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion_root.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:25:39 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:32:41 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	param_exp_find_start(t_list *token, int start, char *quot)
{
	int		esc_next;
	char	*str;

	str = ((t_token *)token->content)->str;
	*quot = 0;
	esc_next = 0;
	while (str[start])
	{
		if (!esc_next && !*quot && (str[start] == '\'' || str[start] == '\"'))
			*quot = str[start];
		else if (!esc_next && *quot && str[start] == *quot)
			*quot = 0;
		if (!esc_next && str[start] == '\\')
		{
			esc_next = 1;
			start++;
			continue ;
		}
		if (!esc_next && *quot != '\'' && str[start] == '$')
			return (start);
		esc_next = 0;
		start++;
	}
	return (-1);
}

static int	param_exp_find_end(t_list *token, int start)
{
	int		end;
	char	*str;

	str = ((t_token *)token->content)->str;
	end = start + 1;
	while (str[end])
	{
		if (str[start + 1] == '?')
			return (start + 1);
		if (!ft_isalnum(str[end]) && str[end] != '_')
			break ;
		end++;
	}
	return (end - 1);
}

static char	*param_exp_get_env(t_control *control, char *str, int len)
{
	char	*value;
	char	**addr_value;

	if (!ft_strncmp(str, "?", len))
		return (ft_itoa(control->exit_status));
	addr_value = env_get_addr(str, len, control->env);
	if (!addr_value)
		value = ft_strdup("");
	else
		value = ft_strdup(*addr_value);
	return (value);
}

static int	parameter_exp(t_list *token, t_control *ctrl,
		t_expansion e, int res)
{
	char	*insert;
	char	*str;

	e.start = param_exp_find_start(token, e.start, &e.quoted);
	while (e.start != -1)
	{
		str = ((t_token *)token->content)->str;
		e.end = param_exp_find_end(token, e.start);
		if (e.end == e.start)
		{
			e.start++;
			continue ;
		}
		insert = param_exp_get_env(ctrl, str + e.start + 1, e.end - e.start);
		if (!insert)
			return (2);
		ft_memmove(str + e.start, str + e.end + 1, ft_strlen(str + e.end));
		res = parameter_expansion2(&token, &insert, &e);
		free(insert);
		if (res)
			return (res);
		e.start = param_exp_find_start(token, e.start, &e.quoted);
	}
	return (0);
}

int	parameter_expansion_root(t_list *token, t_control *control, int filename)
{
	t_expansion	exp;
	int			res;

	res = 0;
	reset_t_expansion(&exp, filename, control);
	return (parameter_exp(token, control, exp, res));
}
