/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:09:19 by asoria            #+#    #+#             */
/*   Updated: 2025/10/24 20:12:29 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init();
	if (NULL == mlx_ptr)
		return (1);
	
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
