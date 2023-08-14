/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:45:20 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/13 12:39:46 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk.h"

static void	signal_handler(int i, siginfo_t *info, void *context)
{
	static int				n = 0;
	static unsigned char	c = 0;

	c |= (i == SIGUSR1);
	n++;
	if (n == 8)
	{
		write(1, &c, 1);
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		kill(info->si_pid, SIGUSR1);
		c = 0;
		n = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	g_sa;

	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\nListening...\n", 14);
	g_sa.__sigaction_u.__sa_sigaction = signal_handler;
	g_sa.sa_flags = SA_SIGINFO;
	sigemptyset(&g_sa.sa_mask);
	if (sigaction(SIGUSR1, &g_sa, NULL) == -1
		|| sigaction(SIGUSR2, &g_sa, NULL) == -1)
		write(1, "Error", 5);
	while (1)
		pause();
}
