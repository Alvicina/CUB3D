/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:12:17 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/12 19:51:39 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void			draw_wall(t_data *data, t_wall *wall, int screen_col);
static int			get_wall_offset(int wall_height);
static int			get_texture_index_increment(
						t_wall *wall, t_img_data *texture);
static t_img_data	*get_wall_texture(t_data *data, t_wall *wall);

void	render_walls(t_data *data)
{
	int		i;
	double	win_dir_ratio;
	t_wall	wall;
	double	ray_dir_deg;

	win_dir_ratio = (double) POV_DEG / (double) WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_dir_deg = (data->player->dir + (POV_DEG / 2)) - (i * win_dir_ratio);
		wall = get_next_wall(
				data,
				data->player->x,
				data->player->y,
				ray_dir_deg);
		wall.height = (WIN_HEIGHT * 64)
			/ get_distance_to_wall(data, &wall, deg2rad(ray_dir_deg));
		draw_wall(data, &wall, i);
		i++;
	}
}

static void	draw_wall(t_data *data, t_wall *wall, int screen_col)
{
	int		texture_increment;
	int		texture_index;
	double	texture_step;
	int		indexes[2];
	int		color;

	wall->offset = get_wall_offset(wall->height);
	wall->texture = get_wall_texture(data, wall);
	texture_step = TEXTURE_LEN / wall->height;
	texture_increment = get_texture_index_increment(wall, wall->texture);
	indexes[0] = 0;
	indexes[1] = 0;
	if (wall->height > WIN_HEIGHT)
		indexes[1] = (wall->height - WIN_HEIGHT) / 2;
	while (indexes[0] < wall->height && indexes[0] < WIN_HEIGHT)
	{
		texture_index = texture_increment
			+ (floor(indexes[1] * texture_step) * wall->texture->line_len);
		color = *((unsigned int *)(texture_index + wall->texture->pixels));
		draw_pixel(data->mlx, screen_col, wall->offset + indexes[0], color);
		indexes[0]++;
		indexes[1]++;
	}
}

static int	get_wall_offset(int wall_height)
{
	if (wall_height > WIN_HEIGHT)
		return (0);
	else
		return (round((WIN_HEIGHT - wall_height) / 2));
}

static int	get_texture_index_increment(t_wall *wall, t_img_data *texture)
{
	if (wall->dir == WEST)
		return (floor(fmod(wall->y, 64)) * (texture->bits_per_pixel / 8));
	if (wall->dir == EAST && fmod(wall->y, 64) == 0)
		return (texture->line_len - (ceil(fmod(wall->y, 64)) + 1)
			* (texture->bits_per_pixel / 8));
	if (wall->dir == EAST)
		return ((texture->line_len) - ceil(fmod(wall->y, 64))
			* (texture->bits_per_pixel / 8));
	if (wall->dir == SOUTH)
		return (floor(fmod(wall->x, 64)) * (texture->bits_per_pixel / 8));
	if (wall->dir == NORTH && fmod(wall->x, 64) == 0)
		return (texture->line_len - (ceil(fmod(wall->x, 64)) + 1)
			* (texture->bits_per_pixel / 8));
	if (wall->dir == NORTH)
		return ((texture->line_len) - (ceil(fmod(wall->x, 64))
				* (texture->bits_per_pixel / 8)));
	return (0);
}

static t_img_data	*get_wall_texture(t_data *data, t_wall *wall)
{
	if (wall->dir == NORTH)
		return (&data->mlx->img_data_n);
	else if (wall->dir == SOUTH)
		return (&data->mlx->img_data_s);
	else if (wall->dir == EAST)
		return (&data->mlx->img_data_e);
	else if (wall->dir == WEST)
		return (&data->mlx->img_data_w);
	return (NULL);
}
