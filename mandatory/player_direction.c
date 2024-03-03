/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:41:38 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 11:05:48 by afidalgo         ###   ########.fr       */
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
	printf("(x, y, dir) = (%d, %d, %d)\n", data->player->x, data->player->y, data->player->dir);
	render_map(data);
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
