/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:00:19 by yaretel-          #+#    #+#             */
/*   Updated: 2025/11/09 01:40:06 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;
	double	mouse_re;
	double	mouse_im;

	zoom_level = 1.2;
	mouse_re = (x - SIZE / 2.0) / fractal->zoom + fractal->offset_x;
	mouse_im = (y - SIZE / 2.0) / fractal->zoom + fractal->offset_y;
	if (zoom == 1)
		fractal->zoom *= zoom_level;
	else if (zoom == -1)
		fractal->zoom /= zoom_level;
	else
		return ;
	fractal->offset_x = mouse_re - (x - SIZE / 2.0) / fractal->zoom;
	fractal->offset_y = mouse_im - (y - SIZE / 2.0) / fractal->zoom;
}

int	handle_x(void *param)
{
	(void)param;
	exit(8);
}

int	handle_mouse(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == 4)
		zoom(fractal, x, y, 1);
	else if (mouse_code == 5)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal);
	return (0);
}

int	handle_input(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		cleanup(fractal);
		free(fractal);
		exit(1);
	}
	if (keysym == XK_w)
		fractal->offset_y += -20 / fractal->zoom;
	if (keysym == XK_a)
		fractal->offset_x += -20 / fractal->zoom;
	if (keysym == XK_s)
		fractal->offset_y += 20 / fractal->zoom;
	if (keysym == XK_d)
		fractal->offset_x += 20 / fractal->zoom;
	if (keysym == XK_q)
		fractal->color += 0x333333;
	draw_fractal(fractal);
	return (0);
}
