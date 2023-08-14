/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd_root.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:51:13 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:12:57 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exe_prepare_simple_cmd(t_token *token, t_control *control)
{
	int	res;

	res = word_expand_root(((t_list **)&token->str), control);
	if (res)
	{
		control->exit_status = 1;
		if (res == 2)
			control->quit = 1;
		return (res);
	}
	if (!list_to_cmd_root(token))
	{
		control->exit_status = 1;
		control->quit = 1;
		return (2);
	}
	return (0);
}

static int	exe_call_builtin(t_simple_cmd *cmd, int id, t_control *control)
{
	if (id == B_ECHO)
		return (buildin_echo(cmd->argv, control));
	else if (id == B_ENV)
		return (buildin_env(control->env, control));
	else if (id == B_EXPORT)
		return (builtin_export(&control->env, cmd->argv, control));
	else if (id == B_UNSET)
		return (builtin_unset(&control->env, cmd->argv, control));
	else if (id == B_CD)
		return (builtin_cd(control->env, cmd->argv, control));
	else if (id == B_EXIT)
		return (builtin_exit(cmd->argv, control));
	else if (id == B_PWD)
		return (builtin_pwd(control));
	return (0);
}

static int	exe_is_builtin(char *argv0)
{
	if (!argv0)
		return (0);
	if (!ft_strcmp(argv0, "echo"))
		return (B_ECHO);
	else if (!ft_strcmp(argv0, "cd"))
		return (B_CD);
	else if (!ft_strcmp(argv0, "pwd"))
		return (B_PWD);
	else if (!ft_strcmp(argv0, "export"))
		return (B_EXPORT);
	else if (!ft_strcmp(argv0, "unset"))
		return (B_UNSET);
	else if (!ft_strcmp(argv0, "env"))
		return (B_ENV);
	else if (!ft_strcmp(argv0, "exit"))
		return (B_EXIT);
	else
		return (0);
}

int	exe_simple_cmd_root(t_token *token, t_control *control)
{
	int	builtin;
	int	res;

	res = exe_prepare_simple_cmd(token, control);
	if (res == 1)
		return (1);
	else if (res == 2)
		return (0);
	if (!exe_perform_arrow((t_simple_cmd *)token->str, control))
	{
		exe_cancel_arrows(control);
		return (0);
	}
	if (!((t_simple_cmd *)token->str)->argv[0])
		;
	else
	{
		builtin = exe_is_builtin(((t_simple_cmd *)token->str)->argv[0]);
		if (builtin)
			exe_call_builtin(((t_simple_cmd *)token->str), builtin, control);
		else
			exe_binary((t_simple_cmd *)token->str, control);
	}
	exe_cancel_arrows(control);
	return (!!control->exit_status);
}
