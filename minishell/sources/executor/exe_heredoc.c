/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 02:49:04 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/20 16:40:31 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	event_hook(void)
{
	return (1);
}

int	exe_redirection_heredoc(t_arrow *arrow, t_control *control)
{
	int		fd;
	char	*line;
	void	*old_event_hook;

	fd = open(".heredoc.tmp", O_TRUNC | O_CREAT | O_WRONLY,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		return (ft_putstr_fd("here_doc", STDERR_FILENO), perror (" \b"), 0);
	g_sig = -1;
	old_event_hook = rl_event_hook;
	rl_event_hook = event_hook;
	line = readline("> ");
	while (line != NULL && ft_strcmp(line, arrow->dest) != 0 && g_sig == -1)
	{
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		line = readline("> ");
	}
	rl_event_hook = old_event_hook;
	free(arrow->dest);
	arrow->dest = ft_strdup(".heredoc.tmp");
	free(line);
	close(fd);
	exe_perform_indirections(arrow, control);
	return (1);
}
