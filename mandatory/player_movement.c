/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:29:54 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/12 19:52:46 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	move_in_dir(t_data *data, double dir_rad);
static void	move_backward(t_data *data);
static void	move_left(t_data *data);
static void	move_right(t_data *data);

void	move(t_data *data, t_direction dir)
{
	if (dir == FORWARD)
		move_in_dir(data, deg2rad(data->player->dir));
	else if (dir == BACKWARD)
		move_backward(data);
	else if (dir == LEFT)
		move_left(data);
	else if (dir == RIGHT)
		move_right(data);
}

static void	move_in_dir(t_data *data, double dir_rad)
{
	if (!is_next_step_a_wall(data, dir_rad))
	{
		data->player->x += (int) round(cos(dir_rad) * MOVE_SPEED);
		data->player->y -= (int) round(sin(dir_rad) * MOVE_SPEED);
	}
}

static void	move_backward(t_data *data)
{
	int	movement_dir;

	movement_dir = data->player->dir + 180;
	if (movement_dir >= 360)
		movement_dir -= 360;
	move_in_dir(data, deg2rad(movement_dir));
}

static void	move_left(t_data *data)
{
	int	movement_dir;

	movement_dir = data->player->dir + 90;
	if (movement_dir >= 360)
		movement_dir -= 360;
	move_in_dir(data, deg2rad(movement_dir));
}

static void	move_right(t_data *data)
{
	int	movement_dir;

	movement_dir = data->player->dir - 90;
	if (movement_dir < 0)
		movement_dir += 360;
	move_in_dir(data, deg2rad(movement_dir));
}
