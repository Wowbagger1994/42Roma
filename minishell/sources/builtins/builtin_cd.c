/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:29:48 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 21:33:52 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_current_dir(char **target)
{
	if (!(getcwd(*target, ft_strlen(*target))))
	{
		errno = 0;
		ft_free((void **)target);
		*target = getcwd(NULL, 0);
		if (!(*target))
			return (0);
	}
	return (1);
}

static int	change_directory(char *target_dir, t_list *env, t_control *control)
{
	char	**oldpwd;
	char	**pwd_env;

	pwd_env = env_get_addr("PWD", 3, env);
	oldpwd = env_get_addr("OLDPWD", 6, env);
	if (chdir(target_dir) == -1)
		return (-1);
	if (oldpwd)
	{
		free(*oldpwd);
		*oldpwd = ft_strdup(control->cwd);
		if (!(*oldpwd))
			return (0);
	}
	if (!(get_current_dir(&control->cwd)))
		return (0);
	if (pwd_env && get_current_dir(pwd_env) == 0)
		return (0);
	return (1);
}

static int	special_change_dir(char *envdir, t_list *env, t_control *control)
{
	char	*dir;

	dir = env_get(envdir, ft_strlen(envdir), env);
	if (!dir)
	{
		ft_perror("cd", envdir, "environment variable not set");
		return (-1);
	}
	return (change_directory(dir, env, control));
}

int	builtin_cd(t_list *env, char **argv, t_control *control)
{
	int	ret;

	if (!argv[1] || !ft_strcmp("~", argv[1]))
		ret = special_change_dir("HOME", env, control);
	else if (!ft_strcmp("-", argv[1]))
	{
		ret = special_change_dir("OLDPWD", env, control);
		if ((ret) == 1)
			ft_putendl_fd(control->cwd, STDOUT_FILENO);
	}
	else
		ret = change_directory(argv[1], env, control);
	if (ret == 0)
		control->quit = 1;
	else if (errno)
		ft_perror(argv[0], argv[1], strerror(errno));
	if (ret == 1)
		control->exit_status = 0;
	else
		control->exit_status = 1;
	if (ret == 0)
		return (0);
	else
		return (1);
}
