/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 03:05:50 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/21 03:48:36 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_perror(char *cmd, char *param, char *str)
{
	const int	fd = STDERR_FILENO;

	ft_putstr_fd("\033[0;91m", fd);
	ft_putstr_fd("minishell: ", fd);
	if (cmd)
	{
		ft_putstr_fd(cmd, fd);
		ft_putstr_fd(": ", fd);
	}
	if (param)
	{
		ft_putstr_fd("`", fd);
		ft_putstr_fd(param, fd);
		ft_putstr_fd("': ", fd);
	}
	if (errno && !str)
		str = strerror(errno);
	if (str)
	{
		ft_putstr_fd("Error: ", fd);
		ft_putendl_fd(str, fd);
	}
	ft_putstr_fd("\033[0m", fd);
	return (-1);
}

void	ft_ambiguous_redirect(char *str, int fd)
{
	ft_putstr_fd("\033[0;91m", fd);
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(": ambiguous redirect\n", fd);
	ft_putstr_fd("\033[0m", fd);
}

void	ft_errno_exit(void)
{
	if (errno == 13)
		exit(126);
	exit(1);
}
