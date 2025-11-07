/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:25:49 by asoria            #+#    #+#             */
/*   Updated: 2025/11/07 19:44:29 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->type = -1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->cx = 0;
	fractal->cy = 0;
	fractal->zx = 0;
	fractal->zy = 0;
	fractal->offset_x = -0.7;
	fractal->offset_y = 0;
	fractal->color = 0x0044BB;
	fractal->zoom = 150;
	fractal->max_iterations = 150;
}

int	init_display(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (NULL == fractal->mlx)
		return (2);
	fractal->win = mlx_new_window(fractal->mlx, SIZE, SIZE, "fract-ol");
	if (NULL == fractal->win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		return (3);
	}
	fractal->img_ptr = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (NULL == fractal->img_ptr)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		return (4);
	}
	fractal->img_px_ptr = mlx_get_data_addr(fractal->img_ptr,
			&fractal->bpp, &fractal->line_len, &fractal->endian);
	return (0);
}
