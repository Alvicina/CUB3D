/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:36:15 by afidalgo          #+#    #+#             */
/*   Updated: 2024/02/27 19:45:45 by afidalgo         ###   ########.fr       */
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
		look_left(data->player);
	if (key == KEY_RIGHT)
		look_right(data->player);
	if (key == KEY_DOWN || key == KEY_S)
		move_backward(data);
	if (key == KEY_UP || key == KEY_W)
		move_forward(data);
	if (key == KEY_A)
		move_left(data);
	if (key == KEY_D)
		move_right(data);
	printf("(x, y, dir) = (%d, %d, %d)\n", data->player->x, data->player->y, data->player->dir);
	// draw(data);
	return (0);
}
