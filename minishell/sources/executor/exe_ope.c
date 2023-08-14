/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:11:48 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 18:39:32 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_and(t_btree *ast, t_control *control)
{
	exe_root(ast->left, control);
	if (control->exit_status == 0)
		exe_root(ast->right, control);
	return (control->exit_status);
}

int	exe_or(t_btree *ast, t_control *control)
{
	exe_root(ast->left, control);
	if (control->exit_status != 0)
		exe_root(ast->right, control);
	return (control->exit_status);
}

int	exe_semi(t_btree *ast, t_control *control)
{
	exe_root(ast->left, control);
	exe_root(ast->right, control);
	return (control->exit_status);
}

int	exe_cmd(t_btree *ast, t_control *control)
{
	if (!exe_simple_cmd_root((t_token *)ast->item, control))
		return (0);
	return (1);
}

int	exe_subshell(t_btree *ast, t_control *control)
{
	pid_t	pid;
	int		status;

	ft_fork(&pid);
	if (pid == 0)
	{
		ft_signalhandler_disable();
		exe_root(ast->left, control);
		exit(control->exit_status);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			control->exit_status = WEXITSTATUS(status);
		else
			control->exit_status = g_sig;
	}
	return (control->exit_status);
}
