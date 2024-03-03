/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:29:54 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 09:43:49 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move(t_data *data, double dir_rad)
{
	if (!is_next_step_a_wall(data, dir_rad))
	{
		data->player->x += (int) round(cos(dir_rad) * MOVE_SPEED);
		data->player->y -= (int) round(sin(dir_rad) * MOVE_SPEED);
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
