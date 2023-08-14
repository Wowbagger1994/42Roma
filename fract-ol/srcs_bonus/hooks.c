/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:06:25 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/10 20:57:38 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
	{
		vars->zoom += 0.05;
		vars->movex = round(vars->movex + ((vars->width >> 1) - x) * 0.05);
		vars->movey = round(vars->movey + ((vars->heigth >> 1) - y) * 0.05);
		vars->f(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (button == 5 && vars->zoom > 0)
	{
		vars->zoom -= 0.05;
		vars->movex = round(vars->movex + ((vars->width >> 1) - x) * 0.05);
		vars->movey = round(vars->movey + ((vars->heigth >> 1) - y) * 0.05);
		vars->f(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

static void	change_const_julia(t_vars *vars, int keycode)
{
	if (vars->f == julia_fractal
		&& (keycode == 18 || keycode == 19 || keycode == 20))
	{
		vars->zoom = 1;
		vars->movex = 0;
		vars->movey = 0;
		if (keycode == 18 && vars->cx != -0.8 && vars->cy != 0.156)
		{
			vars->cx = -0.8;
			vars->cy = 0.156;
		}
		if (keycode == 19 && vars->cx != -0.4 && vars->cy != 0.6)
		{
			vars->cx = -0.4;
			vars->cy = 0.6;
		}
		if (keycode == 20 && vars->cx != 0.285 && vars->cy != 0.001)
		{
			vars->cx = 0.285;
			vars->cy = 0.001;
		}
	}
}

static void	move_hooks(int keycode, t_vars *vars)
{
	if (keycode == 124)
	{
		vars->movex -= 20;
	}
	if (keycode == 123)
	{
		vars->movex += 20;
	}
	if (keycode == 126)
	{
		vars->movey += 20;
	}
	if (keycode == 125)
	{
		vars->movey -= 20;
	}
}

static void	zoom_hooks(int keycode, t_vars *vars)
{
	if (keycode == 69 || keycode == 30)
	{
		vars->zoom += 0.05;
		vars->f(vars);
	}
	if ((keycode == 44 || keycode == 78) && vars->zoom > 0)
	{
		vars->zoom -= 0.05;
		vars->f(vars);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 8
		|| keycode == 69 || keycode == 30 || keycode == 44 || keycode == 78
		|| keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		move_hooks(keycode, vars);
		change_const_julia(vars, keycode);
		zoom_hooks(keycode, vars);
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
