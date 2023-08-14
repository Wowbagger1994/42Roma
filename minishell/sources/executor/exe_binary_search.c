/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_binary_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:06:44 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/21 13:11:18 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exe_actually_search(int *ret, char **bnry_pth,
	char *argv0, char **split)
{
	int			i;
	char		*path;
	struct stat	buf;

	i = -1;
	*(ret) = 0;
	while (*(ret) == 0 && split[++i])
	{
		path = ft_strjoin(split[i], argv0);
		if (!path)
			*(ret) = -1;
		else if (!stat(path, &buf) && S_ISREG(buf.st_mode))
		{
			*bnry_pth = path;
			*(ret) = 1;
		}
		else
			ft_free((void **)&path);
	}
}

int	exe_search_path(char *argv0, t_control *ctrl, char **bnry_pth)
{
	int		ret;
	char	*env;
	char	**split;

	env = env_get("PATH", 4, ctrl->env);
	if (!env)
		return (-2);
	split = ft_split(env, ':');
	if (!split)
		return (0);
	exe_actually_search(&ret, bnry_pth, argv0, split);
	errno = 0;
	ft_array_free(split, ft_array_len(split));
	return (ret);
}
