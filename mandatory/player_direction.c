/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:41:38 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 09:42:10 by afidalgo         ###   ########.fr       */
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
