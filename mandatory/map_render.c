/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:54:57 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/12 18:56:31 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	render_ceiling(t_data *data);
static void	render_floor(t_data *data);

int	render(t_data *data)
{
	if (data->player->directions[1] != 0)
		turn_pov(data, data->player->directions[1]);
	else if (data->player->directions[0] != 0)
		turn_pov(data, data->player->directions[0]);
	if (data->player->movement[0] != 0)
		move(data, data->player->movement[0]);
	else if (data->player->movement[1] != 0)
		move(data, data->player->movement[1]);
	else if (data->player->movement[2] != 0)
		move(data, data->player->movement[2]);
	else if (data->player->movement[3] != 0)
		move(data, data->player->movement[3]);
	render_map(data);
	return (0);
}

void	render_map(t_data *data)
{
	render_ceiling(data);
	render_floor(data);
	render_walls(data);
	mlx_put_image_to_window(
		data->mlx->mlx_ptr,
		data->mlx->win_ptr,
		data->mlx->img_ptr,
		0,
		0);
}

static void	render_ceiling(t_data *data)
{
	int	i;
	int	j;
	int	ceiling_limit;

	ceiling_limit = WIN_HEIGHT / 2;
	i = 0;
	while (i < ceiling_limit)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			draw_pixel(data->mlx, j, i, data->ceiling);
			j++;
		}
		i++;
	}
}

static void	render_floor(t_data *data)
{
	int	i;
	int	j;

	i = WIN_HEIGHT / 2;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			draw_pixel(data->mlx, j, i, data->floor);
			j++;
		}
		i++;
	}
}
