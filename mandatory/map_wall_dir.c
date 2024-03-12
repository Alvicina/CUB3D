/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:42:10 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/12 19:07:07 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_wall_west(t_wall *wall, t_position *position)
{
	wall->dir = WEST;
	wall->x = position->x + position->distance_right;
	if (position->dir_deg > 180)
	{
		wall->y = position->y - (tan(position->dir_rad)
				* position->distance_right);
	}
	else
	{
		wall->y = position->y + (tan(deg2rad(360 - position->dir_deg))
				* position->distance_right);
	}
}

void	get_wall_south(t_wall *wall, t_position *position)
{
	wall->dir = SOUTH;
	wall->y = position->y - position->distance_top;
	if (position->dir_deg > 90)
	{
		wall->x = position->x - (tan(deg2rad(position->dir_deg - 90))
				* position->distance_top);
	}
	else
	{
		wall->x = position->x + (tan(deg2rad(90 - position->dir_deg))
				* position->distance_top);
	}
}

void	get_wall_east(t_wall *wall, t_position *position)
{
	wall->dir = EAST;
	wall->x = position->x - position->distance_left;
	if (position->dir_deg > 180)
	{
		wall->y = position->y - (tan(deg2rad(180 - position->dir_deg))
				* position->distance_left);
	}
	else
	{
		wall->y = position->y + (tan(deg2rad(position->dir_deg - 180))
				* position->distance_left);
	}
}

void	get_wall_north(t_wall *wall, t_position *position)
{
	wall->dir = NORTH;
	wall->y = position->y + position->distance_bottom;
	if (position->dir_deg < 270)
	{
		wall->x = position->x - (tan(deg2rad(270 - position->dir_deg))
				* position->distance_bottom);
	}
	else
	{
		wall->x = position->x + (tan(deg2rad(position->dir_deg - 270))
				* position->distance_bottom);
	}
}

void	get_wall_on_square_junction(t_wall *wall, t_position *position)
{
	if (position->dir_rad == position->top_right_angle)
	{
		wall->y = position->y - position->distance_top;
		wall->x = position->x + position->distance_right;
		wall->dir = SOUTH;
	}
	else if (position->dir_rad == position->top_left_angle)
	{
		wall->y = position->y - position->distance_top;
		wall->x = position->x - position->distance_left;
		wall->dir = EAST;
	}
	else if (position->dir_rad == position->bottom_left_angle)
	{
		wall->y = position->y + position->distance_bottom;
		wall->x = position->x - position->distance_left;
		wall->dir = NORTH;
	}
	else if (position->dir_rad == position->bottom_right_angle)
	{
		wall->y = position->y + position->distance_bottom;
		wall->x = position->x + position->distance_right;
		wall->dir = WEST;
	}
}
