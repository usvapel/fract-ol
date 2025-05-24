/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:31:09 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/19 21:31:17 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_fractal *f, int32_t x, int32_t y)
{
	const long double	x_span = (f->max_x - f->min_x) / f->zoom;
	const long double	y_span = (f->max_y - f->min_y) / f->zoom;
	long double			temp;

	f->rc = map(x, f->fimg->width,
			f->center_x - x_span / 2,
			f->center_x + x_span / 2);
	f->ic = map(y, f->fimg->height,
			f->center_y - y_span / 2,
			f->center_y + y_span / 2);
	f->zr = 0.0;
	f->zi = 0.0;
	f->n = 0;
	while (f->n < f->max_iter)
	{
		temp = f->zr * f->zr - f->zi * f->zi + f->rc;
		f->zi = 2 * f->zr * f->zi + f->ic;
		f->zr = temp;
		if (f->zr * f->zr + f->zi * f->zi > 4)
			break ;
		f->n++;
	}
}

void	draw_mandelbrot(void *param)
{
	uint32_t	color;
	t_fractal	*f;
	int32_t		x;
	int32_t		y;

	f = (t_fractal *)param;
	y = 0;
	while (y < FRACTALWIDTH)
	{
		x = 0;
		while (x < FRACTALHEIGHT)
		{
			calculate_mandelbrot(f, x, y);
			if (f->n == f->max_iter)
				color = 0xFF;
			else
				color = f->palette[f->n * 255 / f->max_iter];
			mlx_put_pixel(f->fimg, x, y, color);
			x++;
		}
		y++;
	}
}
