/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:54:57 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/10 11:15:45 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	render_ceiling(t_data *data);
static void	render_floor(t_data *data);
static void	render_walls(t_data *data);

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
	printf("(x, y, dir) = (%d, %d, %d)\n", data->player->x, data->player->y, data->player->dir);
	render_map(data);
	return (0);
}

void	render_map(t_data *data)
{
	render_ceiling(data);
	render_floor(data);
	render_walls(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
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

static void	render_walls(t_data *data)
{
	int	i;
	int	j;
	int	k;
	double	distance_to_wall;
	double	wall_v_distance;
	int	wall_v_distance_offset;
	double	win_dir_ratio;
	t_wall	wall;
	double	distance_to_wall_x;
	double	distance_to_wall_y;
	double	fish_eye;
	double	ray_dir_deg;
	t_img_data	texture;
	unsigned int			texture_color;
	int			texture_pixel_index;
	double		texture_step;

	win_dir_ratio = (double) POV_DEG / (double) WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_dir_deg = (data->player->dir + (POV_DEG / 2)) - (i * win_dir_ratio);
		wall = get_distance_to_wall(
			data,
			data->player->x,
			data->player->y,
			ray_dir_deg, 0);
		distance_to_wall_x = fabs(data->player->x - wall.x);
		distance_to_wall_y = fabs(data->player->y - wall.y);
		fish_eye = sqrt(pow(distance_to_wall_x, 2) + pow(distance_to_wall_y, 2)); // Teorema de Pitagoras
		distance_to_wall = (cos(fabs(deg2rad(data->player->dir) - deg2rad(ray_dir_deg))) * fish_eye);
		wall_v_distance = (WIN_HEIGHT * 64) / distance_to_wall;
		if (wall_v_distance > WIN_HEIGHT)
			wall_v_distance_offset = 0;
		else	
			wall_v_distance_offset = round((WIN_HEIGHT - wall_v_distance) / 2);
		if (wall.dir == NORTH)
			texture = data->mlx->img_data_N;
		else if (wall.dir == SOUTH)
			texture = data->mlx->img_data_S;
		else if (wall.dir == EAST)
			texture = data->mlx->img_data_E;
		else if (wall.dir == WEST)
			texture = data->mlx->img_data_W;
		texture_step = TEXTURE_LEN / wall_v_distance;
		j = 0;
		if (wall_v_distance > WIN_HEIGHT)
			k = (wall_v_distance - WIN_HEIGHT) / 2;
		else
			k = 0;
		while (j < wall_v_distance && j < WIN_HEIGHT)
		{
			texture_pixel_index = floor(k * texture_step) * texture.line_len;
			if (wall.dir == WEST)
				texture_pixel_index += floor(fmod(wall.y, 64)) * (texture.bits_per_pixel / 8);
			else if (wall.dir == EAST && fmod(wall.y, 64) == 0)
				texture_pixel_index += texture.line_len - (ceil(fmod(wall.y, 64)) + 1) * (texture.bits_per_pixel / 8);
			else if (wall.dir == EAST)
				texture_pixel_index += (texture.line_len) - ceil(fmod(wall.y, 64)) * (texture.bits_per_pixel / 8);
			else if (wall.dir == SOUTH)
				texture_pixel_index += floor(fmod(wall.x, 64)) * (texture.bits_per_pixel / 8);
			else if (wall.dir == NORTH && fmod(wall.x, 64) == 0)
				texture_pixel_index += texture.line_len - (ceil(fmod(wall.x, 64)) + 1) * (texture.bits_per_pixel / 8);
			else if (wall.dir == NORTH)
				texture_pixel_index += (texture.line_len) - (ceil(fmod(wall.x, 64)) * (texture.bits_per_pixel / 8));
			texture_color = *((unsigned int *) (texture_pixel_index + texture.pixels));
			draw_pixel(data->mlx, i, wall_v_distance_offset + j, texture_color);
			j++;
			k++;
		}
		i++;
	}
}
