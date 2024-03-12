/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:20:27 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/12 18:55:54 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_data(t_position *pos, double x, double y, double dir_deg);
static void	get_position_on_y_border(t_position *position, double dir_deg);
static void	get_position_on_x_border(t_position *position, double dir_deg);
static void	get_position_angles(t_position *position);

void	get_position(t_position *position, double x, double y, double dir_deg)
{
	init_data(position, x, y, dir_deg);
	if (fmod(y, TILE_LEN) == 0)
	{
		get_position_on_y_border(position, dir_deg);
	}
	else
	{
		position->distance_top = fmod(y, TILE_LEN);
		position->distance_bottom = TILE_LEN - position->distance_top;
	}
	if (fmod (x, TILE_LEN) == 0)
	{
		get_position_on_x_border(position, dir_deg);
	}
	else
	{
		position->distance_left = fmod(x, TILE_LEN);
		position->distance_right = TILE_LEN - position->distance_left;
	}
	get_position_angles(position);
}

static void	init_data(t_position *pos, double x, double y, double dir_deg)
{
	pos->x = x;
	pos->y = y;
	if (dir_deg >= 360)
		dir_deg -= 360;
	if (dir_deg < 0)
		dir_deg += 360;
	pos->dir_deg = dir_deg;
	pos->dir_rad = deg2rad(dir_deg);
}

static void	get_position_on_y_border(t_position *position, double dir_deg)
{
	if (dir_deg < 180)
	{
		position->distance_top = TILE_LEN;
		position->distance_bottom = 0;
	}
	else
	{
		position->distance_top = 0;
		position->distance_bottom = TILE_LEN;
	}
}

static void	get_position_on_x_border(t_position *position, double dir_deg)
{
	if (dir_deg < 90 || dir_deg > 270)
	{
		position->distance_left = 0;
		position->distance_right = TILE_LEN;
	}
	else
	{
		position->distance_right = 0;
		position->distance_left = TILE_LEN;
	}
}

static void	get_position_angles(t_position *position)
{
	position->top_right_angle = atan(position->distance_top
			/ position->distance_right);
	position->top_left_angle = atan(position->distance_left
			/ position->distance_top) + deg2rad(90);
	position->bottom_left_angle = atan(position->distance_bottom
			/ position->distance_left) + deg2rad(180);
	position->bottom_right_angle = atan(position->distance_right
			/ position->distance_bottom) + deg2rad(270);
}
