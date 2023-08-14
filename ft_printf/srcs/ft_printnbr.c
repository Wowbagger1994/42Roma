/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:41:53 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/21 14:15:52 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static int	ft_printhexpointer(unsigned long long addr, int n)
{
	int				len;
	int				i;
	int				res;
	char			*addr_str;

	len = ft_hexlen(addr) + 2;
	i = 2;
	res = 0;
	addr_str = (char *)malloc(sizeof(char) * len + 1);
	if (len < n)
		res += ft_putspace(n - len + 1);
	addr_str = ft_convert_to_hex(addr, addr_str, len - 1);
	addr_str[len] = '\0';
	res += write(1, "0x", 2);
	while (addr_str[i] != '\0')
		res += write(1, (addr_str + i++), 1);
	free(addr_str);
	return (res);
}

int	ft_puthexpointer(int n, va_list *args)
{
	long long	addr;
	int			res;

	res = 0;
	addr = va_arg(*args, unsigned long long);
	if (addr == 0)
	{
		if (3 < n)
			res += ft_putspace(n - 3 + 1);
		res += write(1, "0x0", 3);
		return (res);
	}
	return (ft_printhexpointer(addr, n));
}

int	ft_putint(int n, va_list *args)
{
	int		num;
	int		len;
	int		res;

	res = 0;
	num = va_arg(*args, int);
	len = ft_numlen(num);
	if (len < n)
		res += ft_putspace(n - len + 1);
	if (num == -2147483648)
		return (res + write(1, "-2147483648", 11));
	else if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	ft_putnbr_fd(num, 1);
	return (res + len);
}

int	ft_puntunsignedint(int n, va_list *args)
{
	unsigned int		num;
	int					len;
	int					res;

	res = 0;
	num = va_arg(*args, unsigned int);
	len = ft_unsignednumlen(num);
	if (len < n)
		res += ft_putspace(n - len + 1);
	ft_putunsingednbr_fd(num, 1);
	return (res + len);
}

int	ft_puthex(char c, unsigned int n, va_list *args)
{
	unsigned int	num;
	unsigned int	len;
	char			*s;
	int				res;
	int				i;

	num = va_arg(*args, unsigned int);
	len = ft_hexlen(num);
	i = 0;
	res = 0;
	if (len < n)
		res += ft_putspace(n - len + 1);
	if (num == 0)
		return (res + write(1, "0", 1));
	s = (char *)malloc(sizeof(char) * len + 1);
	s = ft_convert_to_hex(num, s, len - 1);
	s[len] = '\0';
	while (s[i] != '\0')
	{
		if (c == 'X')
			s[i] = ft_toupper(s[i]);
		res += write(1, (s + i++), 1);
	}
	free(s);
	return (res);
}
