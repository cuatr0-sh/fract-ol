/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:23:13 by asoria            #+#    #+#             */
/*   Updated: 2025/11/02 03:06:54 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define SIZE 400

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	void	*img_px_ptr;
	int	bpp;
	int	line_len;
	int	endian;
	int	type;
	int	x;
	int	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	int	color;
	double	zoom;
	int	max_iterations;
}	t_fractal;

int	init_display(t_fractal *fractal);

int	parse_args(int argc, char **argv, t_fractal *fractal);
int	terminate_program(int exit_code);

int	handle_input(int keysym, t_fractal *fractal);
int	handle_mouse(int mouse_code, int x, int y, t_fractal *fractal);

void	init_fractal(t_fractal *fractal);

void	color_pixel(t_fractal *fractal, int x, int y, int color);
void	draw_fractal(t_fractal *fractal);

void	calculate_mandelbrot(t_fractal *fractal);
#endif
