/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tild_expansion_root.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:32:32 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:59:35 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	index_assignement_sign(char *str)
{
	int	i;

	i = 1;
	if (!str[0] || !ft_isalpha(str[0]))
		return (-1);
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		if (!(ft_isalpha(str[i])))
			return (-1);
		i++;
	}
	return (-1);
}

int	tild_expansion_root(t_list *env, char **str)
{
	char	*home_env;
	int		start_assignement;
	int		index;

	index = 0;
	home_env = env_get("HOME", 4, env);
	if (!home_env)
		return (1);
	start_assignement = index_assignement_sign(*str);
	if (start_assignement == -1)
		return (tild_expand_try(str, home_env, &index));
	else
		return (expand_tild_in_assignement(str, home_env, start_assignement, \
				start_assignement));
}

int	tild_expand_try(char **str, char *home_env, int *i)
{
	int	res;

	if (!is_tild_expandable(*str, *i))
		return (1);
	ft_strcdel(*str, *i);
	res = ft_strstradd(str, *i, home_env);
	if (res)
		*i = *i + ft_strlen(home_env);
	return (res);
}

int	is_tild_expandable(char *str, int i)
{
	if (!str[i])
		return (0);
	if (str[i] != '~')
		return (0);
	i++;
	if (!str[i] || str[i] == '/' || str[i] == ':')
		return (1);
	return (0);
}
