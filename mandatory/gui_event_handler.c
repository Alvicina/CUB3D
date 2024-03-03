/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:36:15 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/03 10:30:15 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	handle_key_down(int key, t_data *data);

void	set_event_hooks(t_data *data)
{
	mlx_hook(data->mlx->win_ptr, 2, 0, handle_key_down, data);
	mlx_hook(data->mlx->win_ptr, 17, (1L << 19), &terminate, data);
}

static int	handle_key_down(int key, t_data *data)
{
	if (key == KEY_ESC)
		terminate(data);
	if (key == KEY_LEFT)
		turn_pov(data, LEFT);
	if (key == KEY_RIGHT)
		turn_pov(data, RIGHT);
	if (key == KEY_DOWN || key == KEY_S)
		move(data, BACKWARD);
	if (key == KEY_UP || key == KEY_W)
		move(data, FORWARD);
	if (key == KEY_A)
		move(data, LEFT);
	if (key == KEY_D)
		move(data, RIGHT);
	return (0);
}
