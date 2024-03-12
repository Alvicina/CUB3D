/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:21:33 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/12 19:21:09 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	image_north(t_data *data, int x)
{
	data->mlx->n_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->n_text,
			&x, &x);
	if (data->mlx->n_img == NULL)
		return (EXIT_FAILURE);
	data->mlx->img_data_n.pixels = mlx_get_data_addr(
			data->mlx->n_img, &data->mlx->img_data_n.bits_per_pixel,
			&data->mlx->img_data_n.line_len, &data->mlx->img_data_n.endian);
	return (EXIT_SUCCESS);
}

int	image_south(t_data *data, int x)
{
	data->mlx->s_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->s_text,
			&x, &x);
	if (data->mlx->s_img == NULL)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->n_img);
		return (EXIT_FAILURE);
	}
	data->mlx->img_data_s.pixels = mlx_get_data_addr(
			data->mlx->s_img, &data->mlx->img_data_s.bits_per_pixel,
			&data->mlx->img_data_s.line_len, &data->mlx->img_data_s.endian);
	return (EXIT_SUCCESS);
}

int	image_east(t_data *data, int x)
{
	data->mlx->e_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->e_text,
			&x, &x);
	if (data->mlx->e_img == NULL)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->n_img);
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->s_img);
		return (EXIT_FAILURE);
	}
	data->mlx->img_data_e.pixels = mlx_get_data_addr(
			data->mlx->e_img, &data->mlx->img_data_e.bits_per_pixel,
			&data->mlx->img_data_e.line_len, &data->mlx->img_data_e.endian);
	return (EXIT_SUCCESS);
}

int	image_west(t_data *data, int x)
{
	data->mlx->w_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->w_text,
			&x, &x);
	if (data->mlx->w_img == NULL)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->n_img);
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->s_img);
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->e_img);
		return (EXIT_FAILURE);
	}
	data->mlx->img_data_w.pixels = mlx_get_data_addr(
			data->mlx->w_img, &data->mlx->img_data_w.bits_per_pixel,
			&data->mlx->img_data_w.line_len, &data->mlx->img_data_w.endian);
	return (EXIT_SUCCESS);
}
