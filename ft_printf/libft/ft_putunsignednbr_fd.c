/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:31:42 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/20 16:32:12 by ebraho           ###   ########.fr       */
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

void	ft_putunsingednbr_fd(unsigned int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
		ft_putnbr_fd_recursive(n, fd);
}
