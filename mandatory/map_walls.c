/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:42:38 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/17 13:21:33 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	get_wall_based_on_dir(t_wall *wall, t_position *position);

int	is_next_step_a_wall(t_data *data, double dir_rad)
{
	int	new_x;
	int	new_y;
	//int	tile_x;
	//int	tile_y;

	new_x = data->player->x + round(cos(dir_rad) * MOVE_SPEED);
	new_y = data->player->y - round(sin(dir_rad) * MOVE_SPEED);
	//tile_x = new_x / TILE_LEN;
	//tile_y = new_y / TILE_LEN;
	if (is_coord_a_wall(data, new_x, new_y))
	{
		printf("Te has chocado\n");
		return (1);
	}
	return (0);
}

int	is_coord_a_wall(t_data *data, double x, double y)
{
	int	tile_x;
	int	tile_y;

	tile_x = x / TILE_LEN;
	tile_y = y / TILE_LEN;
	if (data->map_only[tile_y][tile_x] == '1')
		return (1);
	if (fmod(x, TILE_LEN) == 0)
	{
		if (data->map_only[tile_y][tile_x] == '1'
			|| data->map_only[tile_y][tile_x - 1] == '1')
			return (1);
	}
	if (fmod(y, TILE_LEN) == 0)
	{
		if (data->map_only[tile_y][tile_x] == '1'
			|| data->map_only[tile_y - 1][tile_x] == '1')
			return (1);
	}
	if (fmod(x, TILE_LEN) == 0 && fmod(y, TILE_LEN) == 0)
	{
		if (data->map_only[tile_y - 1][tile_x - 1] == '1')
			return (1);
	}
	return (0);
}

t_wall	get_next_wall(t_data *data, double x, double y, double dir_deg)
{
	t_position	position;
	t_wall		wall;

	wall.x = -1.0;
	wall.y = -1.0;
	get_position(&position, x, y, dir_deg);
	get_wall_on_square_junction(&wall, &position);
	if (wall.x == -1.0 || wall.y == -1.0)
		get_wall_based_on_dir(&wall, &position);
	if (is_coord_a_wall(data, wall.x, wall.y))
		return (wall);
	return (get_next_wall(data, wall.x, wall.y, position.dir_deg));
}

static void	get_wall_based_on_dir(t_wall *wall, t_position *position)
{
	if (position->dir_rad >= position->bottom_right_angle
		|| position->dir_rad <= position->top_right_angle)
		get_wall_west(wall, position);
	else if (position->dir_rad <= position->top_left_angle)
		get_wall_south(wall, position);
	else if (position->dir_rad <= position->bottom_left_angle)
		get_wall_east(wall, position);
	else if (position->dir_rad <= position->bottom_right_angle)
		get_wall_north(wall, position);
}

double	get_distance_to_wall(t_data *data, t_wall *wall, double dir_rad)
{
	double	wall_distance_x;
	double	wall_distance_y;
	double	diag_distance;

	wall_distance_x = fabs(data->player->x - wall->x);
	wall_distance_y = fabs(data->player->y - wall->y);
	diag_distance = sqrt(pow(wall_distance_x, 2) + pow(wall_distance_y, 2));
	return (cos(fabs(deg2rad(data->player->dir) - dir_rad)) * diag_distance);
}
