/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:54:57 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/05 19:36:19 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	render_ceiling_and_floor(t_data *data);
static void	render_walls(t_data *data);

void	render_map(t_data *data)
{
	render_ceiling_and_floor(data);
	render_walls(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
}

static void	render_ceiling_and_floor(t_data *data)
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
			draw_pixel(data->mlx, j, i, 0x0000FF); // TODO: Cambiar por el color del techo
			j++;
		}
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			draw_pixel(data->mlx, j, i, 0x00FF00); // TODO: Cambiar por el color del suelo
			j++;
		}
		i++;
	}
}

static void	render_walls(t_data *data)
{
	int	i;
	int	j;
	double	distance_to_wall;
	double	wall_v_distance;
	double	wall_v_distance_offset;
	double	win_dir_ratio;

	win_dir_ratio = (double) POV_DEG / (double) WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		distance_to_wall = get_distance_to_wall(
			data,
			data->player->x,
			data->player->y,
			(data->player->dir + (POV_DEG / 2)) - (i * win_dir_ratio), 0);
		wall_v_distance = (WIN_HEIGHT * 20) / distance_to_wall;
		if (wall_v_distance > WIN_HEIGHT)
			wall_v_distance = WIN_HEIGHT;
		wall_v_distance_offset = (WIN_HEIGHT - wall_v_distance) / 2;
		j = 0;
		while (j < wall_v_distance)
		{
			draw_pixel(data->mlx, i, round(wall_v_distance_offset) + j, 0xFF0000);
			j++;
		}
		i++;
	}
}
