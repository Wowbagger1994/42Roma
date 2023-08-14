/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:36:57 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/20 21:42:05 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_numlen(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

unsigned int	ft_unsignednumlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

unsigned int	ft_hexlen(unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	*ft_convert_to_hex(unsigned long long n, char *s, unsigned int len)
{
	if (n == 0)
		s[len - 1] = '0';
	while (n != 0)
	{
		s[len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (s);
}
