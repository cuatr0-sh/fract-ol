/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:09:19 by asoria            #+#    #+#             */
/*   Updated: 2025/11/04 03:11:14 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage(void)
{
	ft_printf("Usage: ./fract-ol [fractal] {parameters}\n");
	ft_printf("Example:\n");
	ft_printf("./fract-ol mandelbrot\n");
	ft_printf("./fract-ol julia [real] [imaginary]\n");
}

int	terminate_program(int exit_code)
{
	print_usage();
	exit(exit_code);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	parse_args(argc, argv, fractal);
	if (init_display(fractal) != 0)
		terminate_program(init_display(fractal));
	mlx_key_hook(fractal->win, handle_input, fractal);
	mlx_mouse_hook(fractal->win, handle_mouse, fractal);
	draw_fractal(fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
