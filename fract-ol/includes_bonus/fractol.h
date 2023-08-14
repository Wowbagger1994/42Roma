/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:11:30 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/08 10:52:05 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	float	zoom;
	float	cx;
	float	cy;
	int		width;
	int		heigth;
	int		max_iter;
	int		color;
	float	movex;
	float	movey;
	void	(*f)(struct s_vars*);
}			t_vars;

typedef struct s_mandelbrot
{
	float	left;
	float	top;
	float	xside;
	float	yside;
	float	xscale;
	float	yscale;
	float	x2;
	float	y2;
	float	x0;
	float	y0;
	float	tempx;
	float	x;
	float	y;
	float	old_x;
	float	old_y;
	float	zoom;
	int		px;
	int		py;
	int		period;
	int		iter;
}			t_mandelbrot;

typedef struct s_julia
{
	float	xr;
	float	yi;
	float	tempx;
	float	old_x;
	float	old_y;
	float	cx;
	float	cy;
	float	zoom;
	int		px;
	int		py;
	int		iter;
	int		period;
}			t_julia;

typedef struct s_fern
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	float	r;
}			t_fern;

typedef struct s_rgb
{
	float		r;
	float		g;
	float		b;
}			t_rgb;

typedef struct s_hsb
{
	float		h;
	float		s;
	float		b;
}			t_hsb;

unsigned int	color_pixel(t_vars *vars, int a);
void			mandelbrot_fractal(t_vars *vars);
void			julia_fractal(t_vars *vars);
void			barnsley_fern(t_vars *vars);
void			set_mandelbrot_param(t_mandelbrot *par, t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int				mouse_hook(int button, int x, int y, t_vars *vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
float			get_zoom(float zoom);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
void			*check_error(void *p, char *s);

#endif
