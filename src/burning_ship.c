/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:57:35 by asoria            #+#    #+#             */
/*   Updated: 2025/11/08 14:55:34 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	calculate_burning_ship_2(double cx, double cy, t_fractal *f)
{
	int		i;
	double	tmp;
	double	zx;
	double	zy;

	zx = 0;
	zy = 0;
	i = 0;
	while (i < f->max_iterations && (zx * zx + zy * zy) < 4)
	{
		tmp = zx;
		zx = zx * zx - zy * zy + cx;
		zy = fabs(2 * tmp * zy) + cy;
		zx = fabs(zx);
		i++;
	}
	return (i);
}

void	calculate_burning_ship(t_fractal *f)
{
	int		i;
	double	cx;
	double	cy;

	i = 0;
	cx = ((f->x - SIZE / 2.0) / f->zoom) + f->offset_x;
	cy = ((f->y - SIZE / 2.0) / f->zoom) + f->offset_y;
	i = calculate_burning_ship_2(cx, cy, f);
	if (i == f->max_iterations)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel(f, f->x, f->y, f->color * i / f->max_iterations);
}
