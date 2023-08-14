/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:59:44 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/08 10:55:08 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol.h"

static void	init_params(t_vars *vars, char *name)
{
	vars->width = 720;
	vars->heigth = 360;
	vars->zoom = 1;
	if (vars->f == barnsley_fern)
		vars->max_iter = 100000;
	else
		vars->max_iter = 100;
	vars->cx = -0.8;
	vars->cy = 0.156;
	vars->color = 0;
	vars->movex = 0;
	vars->movey = 0;
	vars->mlx = check_error(mlx_init(), "Mlx initialization failed");
	vars->win = check_error(
			mlx_new_window(vars->mlx, vars->width, vars->heigth, name),
			"Window creation failed");
	vars->img.img = check_error(
			mlx_new_image(vars->mlx, vars->width, vars->heigth),
			"Image creation failed");
	vars->img.addr = check_error(
			mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
				&vars->img.line_length, &vars->img.endian),
			"Mlx get data address failed");
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc > 1 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		vars.f = mandelbrot_fractal;
	else if (argc > 1 && ft_strncmp(argv[1], "julia", 6) == 0)
		vars.f = julia_fractal;
	else if (argc > 1 && ft_strncmp(argv[1], "fern", 5) == 0)
		vars.f = barnsley_fern;
	else
	{
		printf("[Fractal Name] (Required) ex: \"Mandelbrot\", \"Julia\", \"fern\"\n");
		exit(0);
	}
	init_params(&vars, argv[1]);
	vars.f(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
