/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:36:34 by jpelline          #+#    #+#             */
/*   Updated: 2025/05/15 18:29:34 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	init_palette_cyan(uint32_t i)
{
	long double	position;
	long double	shimmer;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	shimmer = 0.9f + 0.1f * sinf(i * 0.2f);
	position = powf(i / (long double)(255), 0.8f);
	r = (uint8_t)(shimmer * (10 + position * 50));
	g = (uint8_t)(80 + position * 200);
	b = (uint8_t)(80 + position * 200);
	i = (r << 24) | (g << 16) | (b << 8) | 255;
	return (i);
}

static uint32_t	init_palette_red(uint32_t i)
{
	long double	position;
	long double	shimmer;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	shimmer = 0.9f + 0.1f * sinf(i * 0.2f);
	position = powf(i / (long double)(255), 0.8f);
	r = (uint8_t)(shimmer * (100 + position * 200));
	g = (uint8_t)(10 + position * 100);
	b = (uint8_t)(80 + position * 200);
	i = (r << 24) | (g << 16) | (b << 8) | 255;
	return (i);
}

static uint32_t	init_palette_blue(uint32_t i)
{
	long double	position;
	long double	shimmer;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	shimmer = 0.9f + 0.1f * sinf(i * 0.2f);
	position = powf(i / (long double)(255), 0.8f);
	r = (uint8_t)(10 + position * 255);
	g = (uint8_t)(10 + position * 255);
	b = (uint8_t)(shimmer * (100 + position * 200));
	i = (r << 24) | (g << 16) | (b << 8) | 255;
	return (i);
}

void	fill_palette(t_fractal *f, int set)
{
	uint32_t	i;

	i = 0;
	while (i < 255)
	{
		if (set == 1)
		{
			f->palette[i] = init_palette_cyan(i) << 2;
			f->j->palette[i] = init_palette_cyan(i) << 2;
		}
		if (set == 2)
		{
			f->palette[i] = init_palette_red(i) << 2;
			f->j->palette[i] = init_palette_red(i) << 2;
		}
		if (set == 3)
		{
			f->palette[i] = init_palette_blue(i) << 2;
			f->j->palette[i] = init_palette_blue(i) << 2;
		}
		i++;
	}
}
