/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 05:12:53 by asoria            #+#    #+#             */
/*   Updated: 2025/11/02 05:52:04 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	i = 0;
	fractal->zx = ((fractal->x - SIZE / 2) / fractal->zoom) + fractal->offset_x;
	fractal->zy = ((fractal->y - SIZE / 2) / fractal->zoom) + fractal->offset_y;
		
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
	{
		color_pixel(fractal, fractal->x, fractal->y, (fractal->color * i / 7.5));
	}
}