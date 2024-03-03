/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:29:14 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 11:04:13 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (data->player == NULL)
		return (EXIT_FAILURE);
	// TODO: Calcular los siguientes valores en base al mapa
	data->player->x = 96;
	data->player->y = 96;
	data->player->dir = 0;
	// data->player->x = 320;
	// data->player->y = 323;
	// data->player->dir = 5.06;
	return (EXIT_SUCCESS);
}
