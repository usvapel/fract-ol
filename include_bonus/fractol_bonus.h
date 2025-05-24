/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:56:38 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/24 14:34:57 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "./libft.h"
# include <MLX42.h>
# include <math.h>
# include <stdlib.h>

# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 320
# define FRACTALWIDTH 320
# define FRACTALHEIGHT 320
# define JULIAWIDTH 320
# define JULIAHEIGHT 320

typedef struct s_julia
{
	long double	rc;
	long double	ic;
	long double	zr;
	long double	zi;
	int32_t		x;
	int32_t		y;
	int32_t		n;
	int32_t		max_iter;
	mlx_image_t	*jimg;
	uint32_t	palette[256];
}				t_julia;

typedef struct s_fractal
{
	long double	rc;
	long double	ic;
	long double	zr;
	long double	zi;
	long double	max_x;
	long double	max_y;
	long double	min_x;
	long double	min_y;
	long double	zoom;
	long double	center_x;
	long double	center_y;
	long double	zoom_factor;
	int32_t		n;
	int32_t		max_iter;
	int32_t		base_iter;
	long double	julia_rc;
	long double	julia_ic;
	mlx_image_t	*fimg;
	mlx_t		*mlx;
	char		*set;
	uint32_t	palette[256];
	t_julia		*j;
}				t_fractal;

// Drawing
void			draw_mandelbrot(void *param);
void			draw_burningship(void *param);
void			draw_julia(void *param);
void			draw_julia_burningship(void *param);
void			draw_julia_mandelbrot(void *param);

// Calculating
void			calculate_mandelbrot(t_fractal *f, int32_t x, int32_t y);
void			calculate_burningship(t_fractal *f, int32_t x, int32_t y);
void			calculate_julia_mandelbrot(t_julia *j);
void			calculate_julia_burningship(t_julia *j);
void			calculate_julia_position(void *param);

// Zoom
void			cursor_hook(long double xpos, long double ypos, void *param);
void			scroll_hook(double xdelta, double ydelta, void *param);

// Color
void			fill_palette(t_fractal *f, int set);
uint32_t		init_palette(uint32_t i);

// Utils
long double		map(long double value, long double in_max,
					long double out_min, long double out_max);
int				init_fractal(t_fractal *init, int ac, char **av);
void			draw_text(t_fractal *f);
void			ft_error(t_fractal *f);
void			key_hook(mlx_key_data_t keydata, void *param);
void			help_menu(void);

#endif // FRACTOL_BONUS_H
