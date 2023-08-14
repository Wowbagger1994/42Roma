/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:52:32 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/13 02:22:11 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/minitalk.h"

static void	ft_putnbr_fd_recursive(int n, int fd)
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

int	ft_atoi(const char *str)
{
	int	n;
	int	is_neg;

	n = 0;
	is_neg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		n *= 10;
		if (!is_neg)
			n += (*str - '0');
		else
			n -= (*str - '0');
		str++;
	}
	return (n);
}

int	send_char(char c, int pid)
{
	int	i;
	int	res;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		if (res == -1)
			return (res);
		usleep(100);
	}
	return (res);
}

int	send_str(char *s, int pid)
{
	int	i;
	int	res;

	i = 0;
	while (s[i] != '\0')
	{
		if (send_char(s[i], pid) == -1)
			return (-1);
		i++;
	}
	return (res);
}
