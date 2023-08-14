/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:55:39 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 13:55:41 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	dim_of_num(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	pow_of_ten(int p)
{
	int	n;

	n = 1;
	while (p-- > 0)
		n *= 10;
	return (n);
}

static void	fill_str(char *str, int n, int dim)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	else if (n == 0)
		ft_strlcpy(str, "0", 2);
	else
	{
		if (n < 0)
		{
			str[i++] = '-';
			dim--;
			n *= -1;
		}
		while (dim-- > 0)
		{
			str[i] = '0' + (n / pow_of_ten(dim));
			n %= pow_of_ten(dim);
			i++;
		}
		str[i] = '\0';
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		dim;

	if (n == -2147483648)
		dim = 11;
	else if (n == 0)
		dim = 1;
	else
		dim = dim_of_num(n);
	str = (char *)malloc(dim + 1);
	if (str == 0)
		return (0);
	fill_str(str, n, dim);
	return (str);
}
