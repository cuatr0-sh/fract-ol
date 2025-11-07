/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 05:12:53 by asoria            #+#    #+#             */
/*   Updated: 2025/11/07 19:34:53 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	x_temp;
	double	zx;
	double	zy;

	i = 0;
	zx = ((fractal->x - SIZE / 2) / fractal->zoom) + fractal->offset_x + 0.7;
	zy = -(((fractal->y - SIZE / 2) / fractal->zoom) + fractal->offset_y);
	while (++i < fractal->max_iterations)
	{
		x_temp = zx * zx - zy * zy + fractal->cx;
		zy = 2.0 * zx * zy + fractal->cy;
		zx = x_temp;
		if (zx * zx + zy * zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		color_pixel(fractal, fractal->x, fractal->y,
			(fractal->color * i / 7.5));
}
