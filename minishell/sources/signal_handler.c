/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:03:20 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:45:28 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigquit_cmd(int sig)
{
	g_sig = SIGCAUGHT + sig;
	printf("Quit: %i\n", sig);
	rl_done = 1;
}

void	ft_sigint_cmd(int sig)
{
	printf("\n");
	g_sig = SIGCAUGHT + sig;
	rl_done = 1;
}

void	ft_sigquit(int sig)
{
	rl_on_new_line();
	rl_redisplay();
	g_sig = SIGCAUGHT + sig;
}

void	ft_sigint(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig = SIGCAUGHT + sig;
}
