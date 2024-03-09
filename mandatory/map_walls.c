/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:42:38 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/09 11:12:24 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_next_step_a_wall(t_data *data, double dir_rad)
{
	int	new_x;
	int	new_y;
	int	tile_x;
	int	tile_y;

	new_x = data->player->x + round(cos(dir_rad) * MOVE_SPEED);
	new_y = data->player->y - round(sin(dir_rad) * MOVE_SPEED);
	tile_x = new_x / TILE_LEN;
	tile_y = new_y / TILE_LEN;
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
		if (data->map_only[tile_y][tile_x] == '1' || data->map_only[tile_y][tile_x - 1] == '1')
			return (1);
	}
	if (fmod(y, TILE_LEN) == 0)
	{
		if (data->map_only[tile_y][tile_x] == '1' || data->map_only[tile_y - 1][tile_x] == '1')
			return (1);
	}
	if (fmod(x, TILE_LEN)== 0 && fmod(y, TILE_LEN) == 0)
	{
		if (data->map_only[tile_y - 1][tile_x - 1] == '1')
			return (1);
	}
	return (0);
}

t_wall	get_distance_to_wall(t_data *data, double x, double y, double dir_deg, int depth)
{
	double	dir_rad;
	double	distance_top;
	double	distance_bottom;
	double	distance_left;
	double	distance_right;
	double	top_right_angle;
	double	top_left_angle;
	double	bottom_left_angle;
	double	bottom_right_angle;
	t_wall	wall;

	wall.x = -1.0;
	wall.y = -1.0;
	if (dir_deg >= 360)
		dir_deg -= 360;
	if (dir_deg < 0)
		dir_deg += 360;
	dir_rad = deg2rad(dir_deg);
	distance_top = fmod(y, TILE_LEN);
	distance_bottom = TILE_LEN - distance_top;
	distance_left = fmod(x, TILE_LEN);
	distance_right = TILE_LEN - distance_left;
	if (fmod(y, TILE_LEN) == 0)
	{
		if (dir_deg < 180)
		{
			distance_top = TILE_LEN;
			distance_bottom = 0;
		}
		else
		{
			distance_top = 0;
			distance_bottom = TILE_LEN;
		}
	}
	if (fmod (x, TILE_LEN) == 0)
	{
		if (dir_deg < 90 || dir_deg > 270)
		{
			distance_left = 0;
			distance_right = TILE_LEN;
		}
		else
		{
			distance_right = 0;
			distance_left = TILE_LEN;
		}
	}
	top_right_angle = atan(distance_top / distance_right);
	top_left_angle = atan(distance_left / distance_top) + deg2rad(90);
	bottom_left_angle = atan(distance_bottom / distance_left) + deg2rad(180);
	bottom_right_angle = atan(distance_right / distance_bottom) + deg2rad(270);
	if (dir_rad == top_right_angle)
	{
		wall.y = y - distance_top;
		wall.x = x + distance_right;
		wall.dir = WEST;
	}
	else if (dir_rad == top_left_angle)
	{
		wall.y = y - distance_top;
		wall.x = x - distance_left;
		wall.dir = SOUTH;
	}
	else if (dir_rad == bottom_left_angle)
	{
		wall.y = y + distance_bottom;
		wall.x = x - distance_left;
		wall.dir = EAST;
	}
	else if (dir_rad == bottom_right_angle)
	{
		wall.y = y + distance_bottom;
		wall.x = x + distance_right;
		wall.dir = NORTH;
	}
	if (wall.x == -1.0 || wall.y == -1.0)
	{
		if (dir_rad >= bottom_right_angle || dir_rad <= top_right_angle) //* Nos movemos a la derecha.
		{
			wall.dir = WEST;
			wall.x = x + distance_right;
			if (dir_deg > 180)
				wall.y = y - (tan(dir_rad) * distance_right); // arriba
			else
				wall.y = y + (tan(deg2rad(360 - dir_deg)) * distance_right); // abajo
		}
		else if (dir_rad <= top_left_angle) //* Nos movemos hacia arriba.
		{
			wall.dir = SOUTH;
			wall.y = y - distance_top;
			if (dir_deg > 90)
				wall.x = x - (tan(deg2rad(dir_deg - 90)) * distance_top);// izquierda
			else
				wall.x = x + (tan(deg2rad(90 - dir_deg)) * distance_top); // derecha
		}
		else if (dir_rad <= bottom_left_angle) //* Nos movemos a la izquierda.
		{
			wall.dir = EAST;
			wall.x = x - distance_left;
			if (dir_deg > 180)
				wall.y = y - (tan(deg2rad(180 - dir_deg)) * distance_left); // arriba
			else
				wall.y = y + (tan(deg2rad(dir_deg - 180)) * distance_left); // abajo
		}
		else if (dir_rad <= bottom_right_angle) //* Nos movemos hacia abajo.
		{
			wall.dir = NORTH;
			wall.y = y + distance_bottom;
			if (dir_deg < 270)
				wall.x = x - (tan(deg2rad(270 - dir_deg)) * distance_bottom); // izquierda
			else
				wall.x = x + (tan(deg2rad(dir_deg - 270)) * distance_bottom); // derecha
		}
		else
		{
			// TODO: Handle error
			printf("El rayo de luz en direccion %f no se encuentra en el rango de ninguna esquina del cuadrante.", dir_deg);
			terminate(data);
		}
	}
	if (is_coord_a_wall(data, wall.x, wall.y))
		return (wall);
	return (get_distance_to_wall(data, wall.x, wall.y, dir_deg, depth + 1));
}
