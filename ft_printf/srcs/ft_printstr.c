/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:40:26 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/21 14:15:21 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(va_list *args)
{
	unsigned char	c;

	c = va_arg(*args, int);
	return (write(1, (unsigned char *)&c, 1));
}

int	ft_putspace(int n)
{
	int	i;

	i = 0;
	while (++i < n)
		write(1, " ", 1);
	return (n - 1);
}

int	ft_putstr(int n, va_list *args)
{
	char	*s;
	int		i;
	int		len;
	int		res;

	i = 0;
	res = 0;
	s = va_arg(*args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	if (len < n)
		res += ft_putspace(n - len + 1);
	while (*(s + i) != '\0')
		res += write(1, (s + i++), 1);
	return (res);
}
