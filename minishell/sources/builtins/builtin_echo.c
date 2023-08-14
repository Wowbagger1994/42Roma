/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:02:11 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 22:26:52 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	buildin_echo(char **argv, t_control *control)
{
	int	i;
	int	n_option;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && ft_isonly(argv[i] + 1, 'n'))
		i++;
	if (i == 1)
		n_option = 0;
	else
		n_option = 1;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[++i])
			ft_putchar_fd(' ', 1);
	}
	if (!n_option)
		ft_putchar_fd('\n', 1);
	control->exit_status = 0;
	return (1);
}
