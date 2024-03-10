/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:23:25 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/10 11:52:12 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void free_massive(t_data *data)
{
	// TODO: Destruir imagenes de texturas
	ft_free_pointer_array(data->textures);
	ft_free_pointer_array(data->map_only);
	ft_free_pointer_array(data->map_spec);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img_ptr);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx);
	free(data->N_text);
	free(data->S_text);
	free(data->E_text);
	free(data->W_text);
}

int	terminate(t_data *data)
{
	free_massive(data);
	exit(EXIT_SUCCESS);
}

double deg2rad(double deg)
{
	return ((deg * PI) / 180);
}

double rad2deg(double rad)
{
	return (rad * (180 / PI));
}
