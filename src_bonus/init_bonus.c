/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:31:30 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/24 14:32:36 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	check_set(t_fractal *init, int ac, char **av)
{
	if (ac > 2)
	{
		if (init->julia_rc == 0 && ft_memcmp("0", av[2], 2) != 0)
			return (0);
		if (init->julia_ic == 0 && ft_memcmp("0", av[3], 2) != 0)
			return (0);
	}
	if (ft_memcmp("Mandelbrot", init->set, 11) == 0)
		return (1);
	if (ft_memcmp("Burningship", init->set, 12) == 0)
		return (1);
	if (ft_memcmp("Julia", init->set, 6) == 0)
		return (1);
	return (0);
}

static void	init_julia(t_julia *init)
{
	init->rc = 0;
	init->ic = 0;
	init->zr = 0;
	init->zi = 0;
	init->x = 0;
	init->y = 0;
	init->n = 0;
	init->max_iter = 100;
}

int	init_fractal(t_fractal *init, int ac, char **av)
{
	init->rc = 0;
	init->ic = 0;
	init->zr = 0;
	init->zi = 0;
	init->max_x = 1.5f;
	init->max_y = 2.0f;
	init->min_x = -2.5f;
	init->min_y = -2.0f;
	init->zoom = 1.0;
	init->center_x = 0.0;
	init->center_y = 0.0;
	init->zoom_factor = 1.05;
	init->n = 0;
	init->max_iter = 200;
	init->base_iter = 200;
	if (ac > 2)
	{
		init->julia_rc = ft_atof(av[2]);
		init->julia_ic = ft_atof(av[3]);
	}
	init->set = ft_strdup(av[1]);
	if (!init->set)
		return (0);
	init_julia(init->j);
	return (check_set(init, ac, av));
}
