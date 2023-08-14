/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:56:25 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/07 18:26:54 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_mandelbrot_param(t_mandelbrot *par, t_vars *vars)
{
	float	minx;
	float	miny;

	minx = (((float)-vars->movex + (vars->width / 2))
			/ (((par->zoom) * 150) / 2)) / -2;
	miny = (((float)-vars->movey + (vars->heigth / 2))
			/ (((par->zoom) * 150) / 2)) / -2;
	par->x0 = par->px / (par->zoom * 150) + minx;
	par->y0 = par->py / (par->zoom * 150) + miny;
	par->x = 0;
	par->y = 0;
	par->x2 = 0;
	par->y2 = 0;
	par->iter = 0;
	par->old_x = -1;
	par->old_y = -1;
	par->period = 0;
}

static void	mandelbrot_algo(t_mandelbrot *par, t_vars *vars)
{
	while ((par->x2 + par->y2 < 4) && (par->iter < vars->max_iter))
	{
		par->y = 2 * par->x * par->y + par->y0;
		par->x = par->x2 - par->y2 + par->x0;
		par->x2 = par->x * par->x;
		par->y2 = par->y * par->y;
		par->iter++;
		if (par->x == par->old_x && par->y == par->old_y)
		{
			par->iter = vars->max_iter;
			break ;
		}
		par->period++;
		if (par->period > 20)
		{
			par->period = 0;
			par->old_x = par->x;
			par->old_y = par->y;
		}
	}
}

void	mandelbrot_fractal(t_vars *vars)
{
	t_mandelbrot	par;

	par.left = -1.8 + (float)vars->movex / 100;
	par.top = -0.725 + (float)vars->movey / 100;
	par.xside = 2.5;
	par.yside = 1.45;
	par.zoom = vars->zoom;
	par.xscale = par.xside / vars->width / par.zoom;
	par.yscale = par.yside / vars->heigth / par.zoom;
	par.py = 1;
	while (par.py < vars->heigth - 1)
	{
		par.py++;
		par.px = 1;
		while (par.px < vars->width - 1)
		{
			par.px++;
			set_mandelbrot_param(&par, vars);
			mandelbrot_algo(&par, vars);
			my_mlx_pixel_put(&(vars->img), par.px, par.py,
				color_pixel(vars, par.iter));
		}
	}
}
