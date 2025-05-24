/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:21:32 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/24 14:32:40 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_julia_position(void *param)
{
	int32_t		mx;
	int32_t		my;
	long double	map_mx;
	long double	map_my;
	t_fractal	*f;

	f = (t_fractal *)param;
	mlx_get_mouse_pos(f->mlx, &mx, &my);
	if (mx > FRACTALWIDTH || mx < 0 || my > FRACTALHEIGHT || my < 0)
	{
		map_mx = 10.0;
		map_my = 10.0;
	}
	else
	{
		map_mx = map((long double)mx, FRACTALWIDTH,
				f->center_x - (f->max_x - f->min_x) / (2 * f->zoom),
				f->center_x + (f->max_x - f->min_x) / (2 * f->zoom));
		map_my = map((long double)my, FRACTALHEIGHT,
				f->center_y - (f->max_y - f->min_y) / (2 * f->zoom),
				f->center_y + (f->max_y - f->min_y) / (2 * f->zoom));
	}
	f->j->rc = map_mx;
	f->j->ic = map_my;
}

void	calculate_julia_mandelbrot(t_julia *j)
{
	long double	temp;

	j->zr = map(j->x, j->jimg->width, -2.0, 2.0);
	j->zi = map(j->y, j->jimg->height, -2.0, 2.0);
	j->n = 0;
	while (j->n < j->max_iter)
	{
		temp = j->zr * j->zr - j->zi * j->zi + j->rc;
		j->zi = 2 * j->zr * j->zi + j->ic;
		j->zr = temp;
		if (j->zr * j->zr + j->zi * j->zi > 4)
			break ;
		j->n++;
	}
}

void	draw_julia_mandelbrot(void *param)
{
	uint32_t	color;
	t_julia		*j;

	j = (t_julia *)param;
	j->y = 0;
	while (j->y < JULIAWIDTH)
	{
		j->x = 0;
		while (j->x < JULIAHEIGHT)
		{
			calculate_julia_mandelbrot(j);
			if (j->n == j->max_iter)
				color = 0xFF;
			else
				color = j->palette[j->n * 255 / j->max_iter];
			mlx_put_pixel(j->jimg, j->x, j->y, color);
			j->x++;
		}
		j->y++;
	}
}

void	calculate_julia_burningship(t_julia *j)
{
	long double	temp;

	j->zr = map(j->x, j->jimg->width, -2.0, 2.0);
	j->zi = map(j->y, j->jimg->height, -2.0, 2.0);
	j->n = 0;
	while (j->n < j->max_iter)
	{
		temp = j->zr * j->zr - j->zi * j->zi + j->rc;
		j->zi = 2 * fabsl(j->zr * j->zi) + j->ic;
		j->zr = temp;
		if (j->zr * j->zr + j->zi * j->zi > 4)
			break ;
		j->n++;
	}
}

void	draw_julia_burningship(void *param)
{
	uint32_t	color;
	t_julia		*j;

	j = (t_julia *)param;
	j->y = 0;
	while (j->y < JULIAWIDTH)
	{
		j->x = 0;
		while (j->x < JULIAHEIGHT)
		{
			calculate_julia_burningship(j);
			if (j->n == j->max_iter)
				color = 0xFF;
			else
				color = j->palette[j->n * 255 / j->max_iter];
			mlx_put_pixel(j->jimg, j->x, j->y, color);
			j->x++;
		}
		j->y++;
	}
}
