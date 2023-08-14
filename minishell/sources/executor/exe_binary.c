/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:49:44 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 13:09:55 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**build_env2d(t_list *env, t_control *control, char **res)
{
	int			i;
	const int	lstsize = ft_lstsize(env);
	t_env		*tmp;
	int			flag;

	i = -1;
	while (env)
	{
		tmp = env->content;
		res[++i] = ft_strjoin_free(tmp->label, (char [2]){'=', '\0'}, 0);
		flag = !!res[i];
		if (flag)
			res[i] = ft_strjoin_free(res[i], tmp->value, 1);
		flag = !!res[i];
		if (!flag)
		{
			control->quit = 1;
			ft_array_free(res, lstsize);
			return (NULL);
		}
		env = env->next;
	}
	return (res);
}

static int	exe_binary_fork(char *prog, char **argv, t_control *control)
{
	char	**env;
	pid_t	pid;
	int		status;

	ft_fork(&pid);
	if (pid == 0)
	{
		env = (char **)ft_memalloc(sizeof(char *)
				* (ft_lstsize(control->env) + 1));
		if ((!env || !build_env2d(control->env, control, env)) && control->quit)
			ft_exit("malloc", NULL, strerror(errno), 1);
		if (execve(prog, argv, env) == -1)
			ft_perror(prog, NULL, strerror(errno));
		ft_array_free(env, ft_array_len(env));
		ft_errno_exit();
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			control->exit_status = WEXITSTATUS(status);
		else
			control->exit_status = g_sig;
	}
	return (1);
}

static int	exe_given_path(char **argv0, t_control *ctrl, char **bnry_pth)
{
	char	*new;

	new = ft_strrchr(*argv0, '/');
	if (!new)
		return (0);
	new = ft_strdup(new + 1);
	if (!new)
	{
		ctrl->quit = 1;
		return (-1);
	}
	*bnry_pth = *argv0;
	*argv0 = new;
	return (1);
}

static int	exe_continue_binary(char **argv0, t_control *control,
		char **path_to_binary, t_simple_cmd *cmd)
{
	int	ret;

	(*argv0) = ft_strjoin((char []){'/', '\0'}, cmd->argv[0]);
	ret = exe_search_path(*argv0, control, path_to_binary);
	if (!(*argv0) || (ret == -1))
		control->quit = 1;
	else if (ret == -2)
	{
		control->exit_status = 127;
		ft_perror(cmd->argv[0], NULL, "No such file or directory");
	}
	else if (ret == 0)
	{
		control->exit_status = 127;
		ft_perror(cmd->argv[0], NULL, "Command not found");
	}
	free(*argv0);
	return (ret);
}

int	exe_binary(t_simple_cmd *cmd, t_control *control)
{
	int		ret;
	char	*argv0;
	char	*path_to_binary;

	g_sig = 1;
	path_to_binary = NULL;
	ret = exe_given_path(&cmd->argv[0], control, &path_to_binary);
	if (ret == -1)
		return (ret);
	else if (ret == 0)
	{
		ret = exe_continue_binary(&argv0, control, &path_to_binary, cmd);
		if (ret != 1)
			return (ret);
	}
	ret = exe_binary_fork(path_to_binary, cmd->argv, control);
	free(path_to_binary);
	return (ret);
}
