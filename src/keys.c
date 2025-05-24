/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:31:50 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/19 21:31:57 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_keys(mlx_key_data_t keydata, t_fractal *f)
{
	uint32_t		i;
	uint32_t		palette_copy[255];
	static int32_t	set = 1;
	static int32_t	shift = 0;

	ft_memcpy(palette_copy, f->palette, sizeof(palette_copy));
	shift = (shift + 1) % 255;
	set = (set % 3) + 1;
	if (keydata.key == MLX_KEY_Y && keydata.action == MLX_PRESS)
		fill_palette(f, set);
	if (keydata.key == MLX_KEY_T && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		i = 0;
		while (i < 255)
		{
			f->palette[i] = palette_copy[(i + shift) % 255];
			f->j->palette[i] = palette_copy[(i + shift) % 255];
			i++;
		}
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		f->center_y -= 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		f->center_y += 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		f->center_x -= 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		f->center_x += 0.1 / f->zoom;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		f->zoom = 1.0;
		f->center_x = 0.0;
		f->center_y = 0.0;
	}
	color_keys(keydata, f);
}
