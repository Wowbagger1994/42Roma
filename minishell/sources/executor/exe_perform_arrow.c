/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_perform_arrow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:51:46 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 20:50:08 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exe_perform_redirections(t_arrow *arrow, t_control *control)
{
	int			fd;
	int			src;
	int			options;
	const int	signals = S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR;

	if (ft_isdigit(arrow->src[0]))
		src = ft_atoi(arrow->src);
	else
		src = 1;
	if (arrow->id == GREAT)
		options = O_TRUNC;
	else
		options = O_APPEND;
	fd = open(arrow->dest, O_WRONLY | O_CREAT | options, signals);
	if (fd < 0)
	{
		ft_perror("open", arrow->dest, strerror(errno));
		return (0);
	}
	if (dup2(fd, src) != -1)
		return (1);
	ft_perror("dup2", NULL, NULL);
	control->quit = 1;
	close(fd);
	return (0);
}

int	exe_perform_indirections(t_arrow *arrow, t_control *control)
{
	int		fd;
	int		src;

	if (ft_isdigit(arrow->src[0]))
		src = ft_atoi(arrow->src);
	else
		src = 0;
	fd = open(arrow->dest, O_RDONLY);
	if (fd < 0)
	{
		ft_perror("open", arrow->dest, strerror(errno));
		return (0);
	}
	if (dup2(fd, src) == -1)
	{
		ft_perror("dup2", NULL, NULL);
		control->quit = 1;
		close(fd);
		return (0);
	}
	return (1);
}

int	exe_perform_arrow(t_simple_cmd *cmd, t_control *control)
{
	t_list const	*arrows = cmd->arrows;
	t_arrow			*arrow;

	while (arrows && arrows->content)
	{
		arrow = arrows->content;
		if (arrow->id == DLESS)
		{
			if (!exe_redirection_heredoc(arrow, control))
			{
				control->exit_status = 1;
				return (0);
			}
		}
		else if ((arrow->id != LESS
				&& !exe_perform_redirections(arrow, control))
			|| (arrow->id == LESS && !exe_perform_indirections(arrow, control)))
		{
			control->exit_status = 1;
			return (0);
		}
		arrows = arrows->next;
	}
	return (1);
}

int	exe_cancel_arrows(t_control *control)
{
	if ((dup2(control->truefd[STDIN_FILENO], STDIN_FILENO)) == -1
		|| (dup2(control->truefd[STDOUT_FILENO], STDOUT_FILENO)) == -1
		|| (dup2(control->truefd[STDERR_FILENO], STDERR_FILENO)) == -1)
	{
		control->quit = 1;
		control->exit_status = 1;
		ft_perror("dup2", NULL, strerror(errno));
		return (0);
	}
	return (1);
}
