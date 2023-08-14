/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:45:20 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/13 12:53:38 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int i)
{
	static int				n = 0;
	static unsigned char	c = 0;

	c |= (i == SIGUSR1);
	n++;
	if (n == 8)
	{
		write(1, &c, 1);
		if (!c)
			write(1, "\n", 1);
		c = 0;
		n = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\nListening...\n", 14);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
