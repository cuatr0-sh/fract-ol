/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:06:38 by asoria            #+#    #+#             */
/*   Updated: 2025/11/07 19:36:52 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_valid_args(int argc, char **argv, t_fractal *fractal)
{
	(void)argv;
	if (fractal->type == 0)
	{
		if (argc != 2)
			terminate_program(4);
		else
			return (0);
	}
	else if (fractal->type == 1)
	{
		if (argc != 4)
			terminate_program(5);
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	return (0);
}

/* Mandlebrot: 0
 * Julia: 1 */
int	parse_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2 || argc > 4)
		terminate_program(3);
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		fractal->type = 0;
	else if (!ft_strncmp(argv[1], "julia", 6))
		fractal->type = 1;
	else
		terminate_program(6);
	check_valid_args(argc, argv, fractal);
	return (0);
}
