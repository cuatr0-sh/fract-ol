/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 02:52:27 by asoria            #+#    #+#             */
/*   Updated: 2025/11/08 14:22:10 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->img_px_ptr;
	buffer[(y * fractal->line_len / 4) + x] = color;
}

void	draw_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			if (fractal->type == 0)
				calculate_mandelbrot(fractal);
			else if (fractal->type == 1)
				calculate_julia(fractal);
			else if (fractal->type == 2)
				calculate_burning_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img_ptr, 0, 0);
}
