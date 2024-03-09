/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:06:47 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/08 17:34:33 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = y * mlx->img_data.line_len;
	pixel_index += (x * (mlx->img_data.bits_per_pixel / 8));
	*((unsigned int *)(pixel_index + mlx->img_data.pixels)) = color;
}
