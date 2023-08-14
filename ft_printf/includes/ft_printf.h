/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:53:03 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/21 14:18:06 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int				ft_printf(const char *str, ...);
unsigned int	ft_numlen(int n);
unsigned int	ft_unsignednumlen(unsigned int n);
unsigned int	ft_hexlen(long long n);
char			*ft_convert_to_hex(long long n, char *s, unsigned int len);
int				ft_putspace(int n);
int				ft_putchar(va_list *args);
int				ft_putstr(int n, va_list *args);
int				ft_putint(int n, va_list *args);
int				ft_puntunsignedint(int n, va_list *args);
int				ft_puthex(char c, unsigned int n, va_list *args);
int				ft_puthexpointer(int n, va_list *args);

#endif
