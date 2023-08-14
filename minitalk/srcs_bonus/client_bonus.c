/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:45:01 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/13 12:39:28 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk.h"

static void	signal_handler(int i)
{
	static int	n = 0;

	if (i == SIGUSR1)
		n++;
	else
	{
		write(1, "Received: ", 10);
		ft_putnbr_fd(n, 1);
		write(1, " byites\n", 8);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	unsigned char	c;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	if (send_str(argv[2], pid) == -1)
		write(1, "Error", 5);
	if (send_char('\0', pid) == -1)
		write(1, "Error", 5);
	while (1)
		pause();
}
