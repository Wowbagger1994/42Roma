/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:10:47 by Wowbagger         #+#    #+#             */
/*   Updated: 2022/01/21 14:16:40 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static int	ft_getprecision(const char **str)
{
	int	n;

	n = 0;
	while (ft_memchr((void *)("0123456789"), (int)(*(*str)), 10))
	{
		n *= 10;
		n += (*(*(str))++) - '0';
	}
	return (n);
}

static int	ft_resolve_argument(const char **str, va_list *args)
{
	int	prec;
	int	res;

	res = 0;
	prec = 0;
	if (ft_memchr((void *)("123456789"), (int)(*(*str)), 9) != 0)
		prec = ft_getprecision(str);
	if (prec > 0 && (*(*str)) != '\0' && (((*(*str) == '%') || (*(*str) == 'c')
				|| ft_memchr("spdiuxX", (int)(*(*(str))), 18) == 0)))
		res += ft_putspace(prec);
	if (**str == '%')
		res += write(1, "%", 1);
	else if (**str == 'c')
		res += ft_putchar(args);
	else if (**str == 's')
		return (ft_putstr(prec, args));
	else if (**str == 'p')
		return (ft_puthexpointer(prec, args));
	else if (**str == 'i' || **str == 'd')
		return (ft_putint(prec, args));
	else if (**str == 'u')
		return (ft_puntunsignedint(prec, args));
	else if (**str == 'x' || **str == 'X')
		return (ft_puthex(**str, prec, args));
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	args;
	char	*arguments;

	res = 0;
	arguments = "123456789cspdiuxX%";
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (ft_memchr((void *)(arguments), (int)(*(++str)), 18) != 0)
			{
				res += ft_resolve_argument(&(str), &args);
				str++;
				continue ;
			}
			if (*(str + 1) == '\0')
				break ;
		}
		res += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (res);
}
