/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:31:06 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 03:06:07 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pipe(int (*fildes)[2])
{
	if (pipe(*fildes) == -1)
		ft_exit("pipe", NULL, strerror(errno), EXIT_FAILURE);
}

void	ft_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		ft_exit("fork", NULL, strerror(errno), EXIT_FAILURE);
	errno = 0;
}

void	ft_fork_pipe(t_pipe *pipe)
{
	ft_pipe(&(pipe->fildes));
	ft_fork(&(pipe->pid));
}

void	ft_exit(char *cmd, char *param, char *str, int status)
{
	ft_perror(cmd, param, str);
	exit(status);
}
