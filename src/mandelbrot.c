/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:46:53 by asoria            #+#    #+#             */
/*   Updated: 2025/10/30 06:35:40 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	static int	first;
	int		i;
	double	x_temp;

	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = ((fractal->x - SIZE / 2) / fractal->zoom) + fractal->offset_x;
	fractal->cy = ((fractal->y - SIZE / 2) / fractal->zoom) + fractal->offset_y;
	
	// debug
	first = 1;
	if (first && fractal->x == 0 && fractal->y == 0)
	{
		printf("First pixel: x=%d, y=%d -> cx=%f, cy=%f\n", 
			fractal->x, fractal->y, fractal->cx, fractal->cy);
		first = 0;
	}

	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		color_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}

