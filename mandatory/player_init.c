/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:29:14 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 14:12:53 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (data->player == NULL)
		return (EXIT_FAILURE);
	// TODO: Calcular los siguientes valores en base al mapa
	// data->player->x = 96;
	// data->player->y = 96;
	// data->player->dir = 0;
	data->player->x = 1023;
	data->player->y = 512;
	data->player->dir = 89;
	return (EXIT_SUCCESS);
}
