/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:23:25 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/12 19:21:09 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_massive(t_data *data)
{
	ft_free_pointer_array(data->textures);
	ft_free_pointer_array(data->map_only);
	ft_free_pointer_array(data->map_spec);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img_ptr);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->n_img);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->s_img);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->e_img);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->w_img);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx);
	free(data->n_text);
	free(data->s_text);
	free(data->e_text);
	free(data->w_text);
}

int	terminate(t_data *data)
{
	free_massive(data);
	exit(EXIT_SUCCESS);
}

double	deg2rad(double deg)
{
	return ((deg * PI) / 180);
}

double	rad2deg(double rad)
{
	return (rad * (180 / PI));
}
