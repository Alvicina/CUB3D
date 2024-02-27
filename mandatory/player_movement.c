/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:29:54 by afidalgo          #+#    #+#             */
/*   Updated: 2024/02/27 19:39:49 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	look_left(t_player *player)
{
	player->dir += TURN_SPEED;
	if (player->dir >= 360)
		player->dir -= 360;
}

void	look_right(t_player *player)
{
	player->dir -= TURN_SPEED;
	if (player->dir < 0)
		player->dir += 360;
}

void	move(t_data *data, double dir_rad)
{
	if (!is_next_step_a_wall(data, dir_rad))
	{
		data->player->x += (int) cos(dir_rad) * MOVE_SPEED;
		data->player->y -= (int) sin(dir_rad) * MOVE_SPEED;
	}
}

void	move_forward(t_data *data)
{
	move(data, deg2rad(data->player->dir));
}

void	move_backward(t_data *data)
{
	int	movement_dir;

	movement_dir = data->player->dir + 180;
	if (movement_dir >= 360)
		movement_dir -= 360;
	move(data, deg2rad(movement_dir));
}

void	move_left(t_data *data)
{
	int	movement_dir;

	movement_dir = data->player->dir + 90;
	if (movement_dir >= 360)
		movement_dir -= 360;
	move(data, deg2rad(movement_dir));
}

void	move_right(t_data *data)
{
	int	movement_dir;

	movement_dir = data->player->dir - 90;
	if (movement_dir < 0)
		movement_dir += 360;
	move(data, deg2rad(movement_dir));
}

int	is_next_step_a_wall(t_data *data, double dir_rad)
{
	int	new_x;
	int	new_y;
	int	tile_x;
	int	tile_y;

	new_x = data->player->x + (cos(dir_rad) * MOVE_SPEED);
	new_y = data->player->y - (sin(dir_rad) * MOVE_SPEED);
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
