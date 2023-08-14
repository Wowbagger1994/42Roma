/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:00:41 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/07 17:41:32 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_rgb	hsb2rgb(t_hsb *h)
{
	float	s;
	float	v;
	float	x;
	t_rgb	rgb;

	s = h->s / 100;
	v = h->b / 100;
	x = s * v * (1 - fabs(fmod(h->h / 60.0, 2) - 1));
	if (h->h >= 0 && h->h < 60)
		rgb = (t_rgb){.r = s * v, .g = x, .b = 0};
	else if (h->h >= 60 && h->h < 120)
		rgb = (t_rgb){.r = x, .g = s * v, .b = 0};
	else if (h->h >= 120 && h->h < 180)
		rgb = (t_rgb){.r = 0, .g = s * v, .b = x};
	else if (h->h >= 180 && h->h < 240)
		rgb = (t_rgb){.r = 0, .g = x, .b = s * v};
	else if (h->h >= 240 && h->h < 300)
		rgb = (t_rgb){.r = x, .g = 0, .b = s * v};
	else
		rgb = (t_rgb){.r = s * v, .g = 0, .b = x};
	rgb.r = (rgb.r + v - s * v) * 255;
	rgb.g = (rgb.g + v - s * v) * 255;
	rgb.b = (rgb.b + v - s * v) * 255;
	return (rgb);
}

static int	ft_fclamp(int n, int min, int max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}

static t_rgb	achromatic_color(t_rgb rgb)
{
	rgb.g = rgb.b;
	rgb.r = rgb.g;
	return (rgb);
}

unsigned int	color_pixel(t_vars *vars, int a)
{
	t_hsb	h;
	double	i;
	t_rgb	rgb;
	int		color;

	i = (double)a / vars->max_iter;
	h = (t_hsb){.h = i * 360, .s = 100, .b = 100};
	rgb = hsb2rgb(&h);
	if (vars->color == 1)
		rgb.r = ft_fclamp((rgb.b + rgb.g) / 4, 0x30, 0xff);
	if (vars->color == 2)
		rgb.b = ft_fclamp((rgb.g + rgb.r) / 4, 0x30, 0xff);
	if (vars->color > 2)
		rgb = achromatic_color(rgb);
	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;
	return (color);
}
