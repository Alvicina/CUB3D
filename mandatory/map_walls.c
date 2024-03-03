/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:42:38 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 14:24:15 by afidalgo         ###   ########.fr       */
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
	if (tile_x >= 0 && tile_y >= 0
		&& tile_y < WIN_HEIGHT && tile_x < WIN_WIDTH
		&& data->map_only[tile_y][tile_x] == '1')
	{
		printf("Te has chocado\n");
		return (1);
	}
	return (0);
}

int	is_coord_a_wall(t_data *data, int x, int y)
{
	int	tile_x;
	int	tile_y;

	// TODO: Obtener las dimensiones del mapa en columnas y descomentar esto.
	// if (x <= 0 || y <= 0 || x >= mlx->map_width * TILE_LEN || y >= mlx->map_height * TILE_LEN)
	// 	return (1);
	tile_x = x / TILE_LEN;
	tile_y = y / TILE_LEN;
	// printf("(x, y) (tile_x, tile_y) = (%d, %d) (%d, %d)\n", x, y, tile_x, tile_y);
	if (x % TILE_LEN == 0)
	{
		if (data->map_only[tile_y][tile_x] == '1' || data->map_only[tile_y][tile_x - 1] == '1')
			return (1);
	}
	if (y % TILE_LEN == 0)
	{
		if (data->map_only[tile_y][tile_x] == '1' || data->map_only[tile_y - 1][tile_x] == '1')
			return (1);
	}
	if (x % TILE_LEN == 0 && y % TILE_LEN == 0)
	{
		if (data->map_only[tile_y - 1][tile_x - 1] == '1')
			return (1);
	}
	return (0);
}

double	get_distance_to_wall(t_data *data, int x, int y, double dir_deg, int depth)
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
	double	wall_x;
	double	wall_y;
	int		wall_x_round;
	int		wall_y_round;
	double	distance_to_wall_x;
	double	distance_to_wall_y;

	wall_x = -1.0;
	wall_y = -1.0;
	if (dir_deg >= 360)
		dir_deg -= 360;
	if (dir_deg < 0)
		dir_deg += 360;
	dir_rad = deg2rad(dir_deg);
	distance_top = y % TILE_LEN;
	distance_bottom = TILE_LEN - distance_top;
	distance_left = x % TILE_LEN;
	distance_right = TILE_LEN - distance_left;
	// printf("(x, y) = (%d, %d)\n", x, y);
	if (y % 64 == 0)
	{
		// if (dir_deg == 180)
		// {
		// 	wall_y = y;
		// 	wall_x = x - distance_left;
		// }
		// else if (dir_deg == 0)
		// {
		// 	wall_y = y;
		// 	wall_x = x + distance_right;
		// }
		// else 
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

	if (x % 64 == 0)
	{
		// if (dir_deg == 90)
		// {
		// 	wall_x = x;
		// 	wall_y = y - distance_top;
		// }
		// else if (dir_deg == 270)
		// {
		// 	wall_x = x;
		// 	wall_y = y + distance_bottom;
		// }
		// else 
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
	// printf("distance_top = %f\n", distance_top);
	// printf("distance_bottom = %f\n", distance_bottom);
	// printf("distance_left = %f\n", distance_left);
	// printf("distance_right = %f\n", distance_right);
	top_right_angle = atan(distance_top / distance_right);
	top_left_angle = atan(distance_left / distance_top) + deg2rad(90);
	bottom_left_angle = atan(distance_bottom / distance_left) + deg2rad(180);
	bottom_right_angle = atan(distance_right / distance_bottom) + deg2rad(270);
	// printf("dir_rad = %f, %f\n", dir_rad, dir_deg);
	// printf("top_right_angle = %f %f\n", top_right_angle, rad2deg(top_right_angle));
	// printf("top_left_angle = %f %f\n", top_left_angle, rad2deg(top_left_angle));
	// printf("bottom_left_angle = %f %f\n", bottom_left_angle, rad2deg(bottom_left_angle));
	// printf("bottom_right_angle = %f %f\n", bottom_right_angle, rad2deg(bottom_right_angle));

	if (dir_rad == top_right_angle || dir_rad == top_left_angle)
		wall_y = y - distance_top;
	else if (dir_rad == bottom_right_angle || dir_rad == bottom_left_angle)
		wall_y = y + distance_bottom;
	if (dir_rad == top_right_angle || dir_rad == bottom_right_angle)
		wall_x = x + distance_right;
	else if (dir_rad == top_left_angle || dir_rad == bottom_left_angle)
		wall_x = x - distance_left;
	
	if (wall_x == -1.0 || wall_y == -1.0)
	{
		if (dir_rad >= bottom_right_angle || dir_rad <= top_right_angle) //* Nos movemos a la derecha.
		{
			// printf("corta derecha\n");
			wall_x = x + distance_right;
			if (dir_deg > 180)
				wall_y = y - (tan(dir_rad) * distance_right); // arriba
			else
				wall_y = y + (tan(deg2rad(360 - dir_deg)) * distance_right); // abajo
		}
		else if (dir_rad <= top_left_angle) //* Nos movemos hacia arriba.
		{
			// printf("corta arriba\n");
			wall_y = y - distance_top;
			if (dir_deg > 90)
				wall_x = x - (tan(deg2rad(dir_deg - 90)) * distance_top);// izquierda
			else
				wall_x = x + (tan(deg2rad(90 - dir_deg)) * distance_top); // derecha
		}
		else if (dir_rad <= bottom_left_angle) //* Nos movemos a la izquierda.
		{
			// printf("corta izquierda\n");
			wall_x = x - distance_left;
			if (dir_deg > 180)
				wall_y = y - (tan(deg2rad(180 - dir_deg)) * distance_left); // arriba
			else
				wall_y = y + (tan(deg2rad(dir_deg - 180)) * distance_left); // abajo
		}
		else if (dir_rad <= bottom_right_angle) //* Nos movemos hacia abajo.
		{
			// printf("corta abajo\n");
			wall_y = y + distance_bottom;
			if (dir_deg < 270)
				wall_x = x - (tan(deg2rad(270 - dir_deg)) * distance_bottom); // izquierda
			else
				wall_x = x + (tan(deg2rad(dir_deg - 270)) * distance_bottom); // derecha
		}
		else
		{
			// TODO: Handle error
			printf("El rayo de luz en direccion %f no se encuentra en el rango de ninguna esquina del cuadrante.", dir_deg);
			terminate(data);
		}
	}
	

	wall_x_round = round(wall_x);
	wall_y_round = round(wall_y);
	// printf("(wall_x, wall_y) = (%f, %f) (%d, %d)\n", wall_x, wall_y, wall_x_round, wall_y_round);
	if (is_coord_a_wall(data, wall_x_round, wall_y_round))
	{
		// TODO: Esto hace efecto ojo de pez
		distance_to_wall_x = fabs(data->player->x - wall_x);
		distance_to_wall_y = fabs(data->player->y - wall_y);
		return (sqrt(pow(distance_to_wall_x, 2) + pow(distance_to_wall_y, 2))); // Teorema de Pitagoras
	}
	else
	{
		// if (depth <= 1)
			return (get_distance_to_wall(data, wall_x_round, wall_y_round, dir_deg, depth + 1));
	}
	return (0);
}
