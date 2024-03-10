/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:29:14 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/09 11:36:02 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	get_player_dir(t_data *data, char c)
{
	if (c == 'N')
		data->player->dir = 90;
	else if (c == 'S')
		data->player->dir = 270;
	else if (c == 'E')
		data->player->dir = 0;
	else if (c == 'W')
		data->player->dir = 180;
}

int	init_player(t_data *data)
{
	size_t	i;
	size_t	j;

	data->player = malloc(sizeof(t_player));
	if (data->player == NULL)
		return (EXIT_FAILURE);
	data->player->directions[0] = 0;
	data->player->directions[1] = 0;
	data->player->movement[0] = 0;
	data->player->movement[1] = 0;
	data->player->movement[2] = 0;
	data->player->movement[3] = 0;
	i = 0;
	while (data->map_only[i])
	{
		j = 0;
		while (data->map_only[i][j])
		{
			if (!ft_comp(data->map_only[i][j], "NSEW"))
			{
				data->player->x = j * 64 + 32;
				data->player->y = i * 64 + 32;
				get_player_dir(data, data->map_only[i][j]);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
int	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (data->player == NULL)
		return (EXIT_FAILURE);
	// TODO: Calcular los siguientes valores en base al mapa
	// data->player->x = 96;
	// data->player->y = 96;
	// data->player->dir = 0;
	data->player->x = 352;
	data->player->y = 352;
	data->player->dir = 195;
	return (EXIT_SUCCESS);
}*/
