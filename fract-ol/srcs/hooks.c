/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:06:25 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/10 20:57:14 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
	{
		vars->zoom += 0.05;
		vars->f(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (button == 5 && vars->zoom > 0)
	{
		vars->zoom -= 0.05;
		vars->f(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	x = 0;
	y = 0;
	return (0);
}

void	change_const_julia(t_vars *vars, int keycode)
{
	if (keycode == 18 && vars->cx != -0.8 && vars->cy != 0.156
		&& vars->f == julia_fractal)
	{
		vars->cx = -0.8;
		vars->cy = 0.156;
		vars->zoom = 1;
	}
	if (keycode == 19 && vars->cx != -0.4 && vars->cy != 0.6
		&& vars->f == julia_fractal)
	{
		vars->cx = -0.4;
		vars->cy = 0.6;
		vars->zoom = 1;
	}
	if (keycode == 20 && vars->cx != 0.285 && vars->cy != 0.001
		&& vars->f == julia_fractal)
	{
		vars->cx = 0.285;
		vars->cy = 0.001;
		vars->zoom = 1;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 8
		|| keycode == 69 || keycode == 30 || keycode == 44 || keycode == 78)
	{
		change_const_julia(vars, keycode);
		if (keycode == 8)
		{
			if (vars->color == 3)
				vars->color = 0;
			else
				vars->color++;
		}
		vars->f(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}
