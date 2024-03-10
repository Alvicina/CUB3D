/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:36:15 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/10 12:08:36 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	handle_key_down(int key, t_data *data);
static int	handle_key_up(int key, t_data *data);
static void	set_movement(t_data *data, t_direction dir);
static void	unset_movement(t_data *data, t_direction dir);

void	set_event_hooks(t_data *data)
{
	mlx_hook(data->mlx->win_ptr, ON_KEYDOWN, 0, handle_key_down, data);
	mlx_hook(data->mlx->win_ptr, ON_KEYUP, 0, handle_key_up, data);
	mlx_hook(data->mlx->win_ptr, ON_DESTROY, (1L << 19), &terminate, data);
	mlx_loop_hook(data->mlx->mlx_ptr, render, data);
}

static int	handle_key_down(int key, t_data *data)
{
	if (key == KEY_ESC)
		terminate(data);
	if (key == KEY_LEFT)
		set_direction(data, LEFT);
	if (key == KEY_RIGHT)
		set_direction(data, RIGHT);
	if (key == KEY_DOWN || key == KEY_S)
		set_movement(data, BACKWARD);
	if (key == KEY_UP || key == KEY_W)
		set_movement(data, FORWARD);
	if (key == KEY_A)
		set_movement(data, LEFT);
	if (key == KEY_D)
		set_movement(data, RIGHT);
	return (0);
}

static int	handle_key_up(int key, t_data *data)
{
	if (key == KEY_LEFT)
		unset_direction(data, LEFT);
	if (key == KEY_RIGHT)
		unset_direction(data, RIGHT);
	if (key == KEY_DOWN || key == KEY_S)
		unset_movement(data, BACKWARD);
	if (key == KEY_UP || key == KEY_W)
		unset_movement(data, FORWARD);
	if (key == KEY_A)
		unset_movement(data, LEFT);
	if (key == KEY_D)
		unset_movement(data, RIGHT);
	return (0);
}

static void	set_movement(t_data *data, t_direction dir)
{
	if (data->player->movement[0] != dir && data->player->movement[1] != dir
		&& data->player->movement[2] != dir && data->player->movement[3] != dir)
	{
		if (data->player->movement[0] == 0)
			data->player->movement[0] = dir;
		else if (data->player->movement[1] == 0)
			data->player->movement[1] = dir;
		else if (data->player->movement[2] == 0)
			data->player->movement[2] = dir;
		else if (data->player->movement[3] == 0)
			data->player->movement[3] = dir;	
	}
}

static void	unset_movement(t_data *data, t_direction dir)
{
	if (data->player->movement[0] == dir)
		data->player->movement[0] = 0;
	else if (data->player->movement[1] == dir)
		data->player->movement[1] = 0;
	else if (data->player->movement[2] == dir)
		data->player->movement[2] = 0;
	else if (data->player->movement[3] == dir)
		data->player->movement[3] = 0;
}
