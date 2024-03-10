/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:41:38 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/10 12:08:00 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	look_left(t_player *player);
static void	look_right(t_player *player);

void	turn_pov(t_data *data, t_direction dir)
{
	if (dir == LEFT)
		look_left(data->player);
	else if (dir == RIGHT)
		look_right(data->player);
}

static void	look_left(t_player *player)
{
	player->dir += TURN_SPEED;
	if (player->dir >= 360)
		player->dir -= 360;
}

static void	look_right(t_player *player)
{
	player->dir -= TURN_SPEED;
	if (player->dir < 0)
		player->dir += 360;
}

void	set_direction(t_data *data, t_direction dir)
{
	if (data->player->directions[0] != dir && data->player->directions[1] != dir)
	{
		if (data->player->directions[0] == 0)
			data->player->directions[0] = dir;
		else
			data->player->directions[1] = dir;
	}
}

void	unset_direction(t_data *data, t_direction dir)
{
	if (data->player->directions[0] == dir)
	{
		if (data->player->directions[1] == 0)
		{
			data->player->directions[0] = 0;
		}
		else
		{
			data->player->directions[0] = data->player->directions[1];
			data->player->directions[1] = 0;
		}
	}
	else if (data->player->directions[1] == dir)
	{
		data->player->directions[1] = 0;
	}
}
