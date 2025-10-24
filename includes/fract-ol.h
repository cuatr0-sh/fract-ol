/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:23:13 by asoria            #+#    #+#             */
/*   Updated: 2025/10/25 01:24:50 by asoria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int	color;
}	t_data;

#endif
