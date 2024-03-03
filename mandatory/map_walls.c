/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:42:38 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 09:44:43 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_next_step_a_wall(t_data *data, double dir_rad)
{
	int	new_x;
	int	new_y;
	int	tile_x;
	int	tile_y;

	new_x = data->player->x + round(cos(dir_rad) * MOVE_SPEED);
	new_y = data->player->y - round(sin(dir_rad) * MOVE_SPEED);
	tile_x = new_x / TILE_LEN;
	tile_y = new_y / TILE_LEN;
	if (tile_x >= 0 && tile_y >= 0
		&& tile_y < WIN_HEIGHT && tile_x < WIN_WIDTH
		&& data->map_only[tile_y][tile_x] == '1')
	{
		printf("Te has chocado\n");
		return (1);
	}
	return (0);
}
