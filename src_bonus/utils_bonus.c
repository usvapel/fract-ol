/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:41:10 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/24 14:32:46 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline long double	map(long double value, long double in_max,
		long double out_min, long double out_max)
{
	return (value * (out_max - out_min) / in_max + out_min);
}

void	draw_text(t_fractal *f)
{
	mlx_put_string(f->mlx, f->set, 20, 10);
	if (ft_memcmp("Julia", f->set, 6) != 0)
		mlx_put_string(f->mlx, "Julia set", 340, 10);
	mlx_put_string(f->mlx, "Scroll to zoom", 650, 10);
	mlx_put_string(f->mlx, "Move the view using:", 650, 40);
	mlx_put_string(f->mlx, "  ^  ", 855, 25);
	mlx_put_string(f->mlx, "  .  ", 855, 35);
	mlx_put_string(f->mlx, "<   >", 855, 40);
	mlx_put_string(f->mlx, "  v  ", 855, 55);
	mlx_put_string(f->mlx, "Reset view: R", 650, 70);
	mlx_put_string(f->mlx, "Modify current colorset: T", 650, 100);
	mlx_put_string(f->mlx, "Switch colorset: Y", 650, 130);
}

void	help_menu(void)
{
	ft_printf("/--------------------------------------------------\\\n");
	ft_printf("|  Fractol mini-guide :)                           |\n");
	ft_printf("|                                                  |\n");
	ft_printf("|  ./fractol Mandelbrot                            |\n");
	ft_printf("|  ./fractol Burningship                           |\n");
	ft_printf("|  ./fractol Julia -0.4    0.6                     |\n");
	ft_printf("|                   0.285  0.01                    |\n");
	ft_printf("|                  -0.8    0.156                   |\n");
	ft_printf("|                   0.35   0.35                    |\n");
	ft_printf("|                  -0.848 -0.001                   |\n");
	ft_printf("|                                                  |\n");
	ft_printf("|                                                  |\n");
	ft_printf("\\--------------------------------------------------/\n");
}

void	ft_error(t_fractal *f)
{
	ft_printf("Error\n");
	help_menu();
	if (f->mlx)
		mlx_terminate(f->mlx);
	if (f->j)
		free(f->j);
	if (f->set)
		free(f->set);
	exit(EXIT_FAILURE);
}
