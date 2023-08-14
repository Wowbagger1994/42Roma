/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:45:01 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/13 12:35:22 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	int				pid;
	int				i;
	int				j;
	unsigned char	c;

	if (argc == 1)
		return (0);
	pid = ft_atoi(argv[1]);
	j = 0;
	while (argv[2][j] != '\0')
	{
		if (send_char(argv[2][j], pid) == -1)
		{
			write(1, "Error", 5);
			exit(0);
		}
		j++;
	}
	if (send_char('\0', pid) == -1)
		write(1, "Error", 5);
}
