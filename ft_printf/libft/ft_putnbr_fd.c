/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:52:33 by Wowbagger         #+#    #+#             */
/*   Updated: 2022/01/20 16:30:50 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_fd_recursive(unsigned int n, int fd)
{
	char	c;

	if (n <= 0)
		return ;
	c = '0' + (n % 10);
	ft_putnbr_fd_recursive(n / 10, fd);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd_recursive(n, fd);
	}
	else
		ft_putnbr_fd_recursive(n, fd);
}
