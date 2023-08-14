/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:28:08 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:49:43 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	termios_enable_raw_mode(t_control *control, struct termios *old)
{
	struct termios	new;
	struct termios	current;

	if (tcgetattr(STDIN_FILENO, &current) == -1)
	{
		control->quit = 1;
		control->exit_status = 1;
		ft_perror("tcgetattr can't get", NULL, strerror(errno));
		return (0);
	}
	new = *old;
	new.c_lflag &= ~(ECHOCTL);
	new.c_lflag &= ~(ICANON);
	new.c_lflag &= ~(ISIG);
	new.c_cc[VTIME] = 1;
	new.c_cc[VMIN] = 0;
	if (ft_memcmp(&current, &new, sizeof(struct termios))
		&& tcsetattr(STDIN_FILENO, TCSAFLUSH, &new) == -1)
	{
		control->quit = 1;
		control->exit_status = 1;
		ft_perror("tcsetattr can't set", NULL, strerror(errno));
		return (0);
	}
	return (1);
}

int	termios_reset_cooked_mode(t_control *control, struct termios *saved_copy)
{
	struct termios	new;

	if (tcgetattr(STDIN_FILENO, &new) == -1)
	{
		control->quit = 1;
		control->exit_status = 1;
		ft_perror("tcgetattr can't get", NULL, strerror(errno));
		return (0);
	}
	if (!ft_memcmp(saved_copy, &new, sizeof(struct termios)))
		return (1);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, saved_copy) == -1)
	{
		control->quit = 1;
		control->exit_status = 1;
		ft_perror("tcsetattr can't reset", NULL, strerror(errno));
		return (0);
	}
	return (1);
}
