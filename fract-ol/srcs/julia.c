/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:04:15 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/07 17:41:16 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	julia_algo(t_julia *par, t_vars *vars)
{
	par->period = 0;
	while ((pow(par->xr, 2) + pow(par->yi, 2) < 4)
		&& (par->iter < vars->max_iter))
	{
		par->tempx = par->xr * par->xr - par->yi * par->yi;
		par->yi = 2 * par->xr * par->yi + par->cy;
		par->xr = par->tempx + par->cx;
		par->iter++;
		if (par->xr == par->old_x && par->yi == par->old_y)
		{
			par->iter = vars->max_iter;
			break ;
		}
		par->period++;
		if (par->period > 20)
		{
			par->period = 0;
			par->old_x = par->xr;
			par->old_y = par->yi;
		}
	}
}

void	julia_fractal(t_vars *vars)
{
	t_julia	par;

	par.zoom = vars->zoom;
	par.cx = vars->cx;
	par.cy = vars->cy;
	par.py = 0;
	while (par.py < vars->heigth - 1)
	{
		par.py++;
		par.px = 0;
		while (par.px < vars->width - 1)
		{
			par.px++;
			par.xr = 1.5 * (par.px + vars->movex - vars->width / 2.0)
				/ (0.5 * par.zoom * vars->width);
			par.yi = (par.py + vars->movey - vars->heigth / 2.0)
				/ (0.5 * par.zoom * vars->heigth);
			par.iter = 0;
			par.old_x = par.xr;
			par.old_y = par.yi;
			julia_algo(&par, vars);
			my_mlx_pixel_put(&(vars->img), par.px, par.py,
				color_pixel(vars, par.iter));
		}
	}
}
