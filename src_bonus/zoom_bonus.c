/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:39:47 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/24 14:32:50 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	handle_zoom_with_scroll(t_fractal *f, double ydelta)
{
	long double	zoom_lvl;

	if (ydelta > 0)
	{
		f->zoom *= f->zoom_factor;
		zoom_lvl = log10(f->zoom);
		f->max_iter = f->base_iter + (int32_t)(zoom_lvl * zoom_lvl * 10);
	}
	else if (ydelta < 0)
	{
		f->zoom /= f->zoom_factor;
		if (f->zoom < 1.0)
			f->zoom = 1.0;
		zoom_lvl = log10(f->zoom);
		f->max_iter = f->base_iter + (int32_t)(zoom_lvl * zoom_lvl * 10);
		if (f->max_iter < f->base_iter)
			f->max_iter = f->base_iter;
	}
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	int32_t		mx;
	int32_t		my;
	long double	mr;
	long double	mi;
	t_fractal	*f;

	(void)xdelta;
	f = (t_fractal *)param;
	mlx_get_mouse_pos(f->mlx, &mx, &my);
	mr = map(mx, FRACTALWIDTH,
			f->center_x - (f->max_x - f->min_x) / (2 * f->zoom),
			f->center_x + (f->max_x - f->min_x) / (2 * f->zoom));
	mi = map(my, FRACTALHEIGHT,
			f->center_y - (f->max_y - f->min_y) / (2 * f->zoom),
			f->center_y + (f->max_y - f->min_y) / (2 * f->zoom));
	handle_zoom_with_scroll(f, ydelta);
	f->center_x = mr - (mx - FRACTALWIDTH / 2.0)
		* (f->max_x - f->min_x)
		/ (f->zoom * FRACTALWIDTH);
	f->center_y = mi - (my - FRACTALHEIGHT / 2.0)
		* (f->max_y - f->min_y)
		/ (f->zoom * FRACTALHEIGHT);
}
