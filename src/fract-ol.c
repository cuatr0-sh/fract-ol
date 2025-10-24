/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:09:19 by asoria            #+#    #+#             */
/*   Updated: 2025/10/25 01:30:00 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract-ol.h"

int	f(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed %d\n", keysym);
	sleep(1);
	return (1);
}

int	change_color(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 150, 150, data->color, "Color Changing Window!");
	
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;

	return (0);
}

int	button_press(int button, int x, int y, t_data *data)
{
	(void)data;
	if (button == 1)
		ft_printf("Left mouse button has been pressed at (%d, %d)\n\n", x, y);
	if (button == 2)
		ft_printf("Right mouse button has been pressed at (%d, %d)\n\n", x, y);
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	/* Declaration and init */
	t_data	data;

	(void)argc;
	(void)argv;

	data.mlx = NULL;
	data.mlx = mlx_init();
	if (NULL == data.mlx)
		return (1);

	data.win = mlx_new_window(data.mlx, 400, 400, "fract-ol");
	if (NULL == data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (2);
	}
	
	/* The sauce */
	
	data.color = 0xFF0000;
	mlx_key_hook(data.win, f, &data);
	//mlx_hook(data.win, ButtonPress, ButtonPressMask, &button_press, &data);
	mlx_loop_hook(data.mlx, change_color, &data);
	mlx_loop(data.mlx);
	
	/* Cleaning up */
	return (0);
}
