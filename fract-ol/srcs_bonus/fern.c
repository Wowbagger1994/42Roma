/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:17:09 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/07 21:19:18 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol.h"

static void	barnsley_fern_algo(t_fern *par)
{
	par->r = rand() % 100;
	if (par->r == 0)
	{
		par->x1 = 0;
		par->y1 = 0.16 * par->y0;
	}
	else if (par->r >= 1 && par->r <= 7)
	{
		par->x1 = -0.15 * par->x0 + 0.28 * par->y0;
		par->y1 = 0.26 * par->x0 + 0.24 * par->y0 + 0.44;
	}
	else if (par->r >= 8 && par->r <= 15)
	{
		par->x1 = 0.2 * par->x0 - 0.26 * par->y0;
		par->y1 = 0.23 * par->x0 + 0.22 * par->y0 + 1.6;
	}
	else
	{
		par->x1 = 0.85 * par->x0 + 0.04 * par->y0;
		par->y1 = -0.04 * par->x0 + 0.85 * par->y0 + 1.6;
	}
}

void	barnsley_fern(t_vars *vars)
{
	t_fern	par;

	par.x0 = 0;
	par.y0 = 0;
	while (vars->max_iter > 0)
	{
		barnsley_fern_algo(&par);
		my_mlx_pixel_put(&(vars->img), 30 * par.x1 + vars->width
			/ 2.0, 30 * par.y1, 0x0000ff00);
		par.x0 = par.x1;
		par.y0 = par.y1;
		vars->max_iter--;
	}
}
