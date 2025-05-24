/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:49:54 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/15 18:34:25 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_fractals(t_fractal *f)
{
	if (ft_memcmp("Mandelbrot", f->set, 10) == 0)
	{
		mlx_loop_hook(f->mlx, draw_mandelbrot, f);
		mlx_loop_hook(f->mlx, calculate_julia_position, f);
		mlx_loop_hook(f->mlx, draw_julia_mandelbrot, f->j);
	}
	else if (ft_memcmp("Burningship", f->set, 11) == 0)
	{
		mlx_loop_hook(f->mlx, draw_burningship, f);
		mlx_loop_hook(f->mlx, calculate_julia_position, f);
		mlx_loop_hook(f->mlx, draw_julia_burningship, f->j);
	}
	else
	{
		mlx_loop_hook(f->mlx, draw_julia, f);
	}
}

static void	setup_resources(t_fractal *f, int ac, char **av)
{
	if (ac < 2 || (ac >= 2 && ac != 4 && ft_memcmp("Julia", av[1], 5) == 0))
	{
		ft_printf("Error: Invalid arguments!\n");
		help_menu();
		exit(EXIT_FAILURE);
	}
	f->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "fract'ol", false);
	if (!f->mlx)
		ft_error(f);
	f->j = malloc(sizeof(t_julia));
	if (!f->j || init_fractal(f, ac, av) == 0)
		ft_error(f);
	f->fimg = mlx_new_image(f->mlx, FRACTALWIDTH, FRACTALHEIGHT);
	if (!f->fimg || mlx_image_to_window(f->mlx, f->fimg, 0, 0) < 0)
		ft_error(f);
	if (ft_memcmp("Mandelbrot", f->set, 10) == 0
		|| ft_memcmp("Burningship", f->set, 11) == 0)
	{
		f->j->jimg = mlx_new_image(f->mlx, JULIAWIDTH, JULIAHEIGHT);
		if (!f->j->jimg)
			ft_error(f);
		if (mlx_image_to_window(f->mlx, f->j->jimg, 320, 0) < 0)
			ft_error(f);
	}
}

int	main(int ac, char **av)
{
	t_fractal	f;

	setup_resources(&f, ac, av);
	fill_palette(&f, 1);
	draw_text(&f);
	draw_fractals(&f);
	mlx_scroll_hook(f.mlx, scroll_hook, &f);
	mlx_key_hook(f.mlx, key_hook, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	free(f.set);
	free(f.j);
	return (EXIT_SUCCESS);
}
