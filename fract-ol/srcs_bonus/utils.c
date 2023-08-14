/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:09:15 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/08 10:52:17 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (c + 32);
	return (c);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && ft_tolower(s1[i]) == ft_tolower(s2[i])
		&& (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (i == n)
		i--;
	res = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
	return (res);
}

void	*check_error(void *p, char *s)
{
	if (p == 0)
	{
		if (*s != '\0')
			perror(s);
		else
			perror(strerror(errno));
		exit(-1);
	}
	return (p);
}
