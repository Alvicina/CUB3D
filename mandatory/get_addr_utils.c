/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:21:33 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/10 12:38:20 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	image_north(t_data *data, int x)
{
	data->mlx->N_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->N_text,
		&x, &x);
	if (data->mlx->N_img == NULL)
		return (EXIT_FAILURE);
	data->mlx->img_data_N.pixels = mlx_get_data_addr(
		data->mlx->N_img, &data->mlx->img_data_N.bits_per_pixel,
		&data->mlx->img_data_N.line_len, &data->mlx->img_data_N.endian);
	return (EXIT_SUCCESS);
}

int	image_south(t_data *data, int x)
{
	data->mlx->S_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->S_text,
		&x, &x);
	if (data->mlx->S_img == NULL)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->N_img);
		return (EXIT_FAILURE);
	}
	data->mlx->img_data_S.pixels = mlx_get_data_addr(
		data->mlx->S_img, &data->mlx->img_data_S.bits_per_pixel,
		&data->mlx->img_data_S.line_len, &data->mlx->img_data_S.endian);
	return (EXIT_SUCCESS);
}

int	image_east(t_data *data, int x)
{
	data->mlx->E_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->E_text,
		&x, &x);
	if (data->mlx->E_img == NULL)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->N_img);
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->S_img);
		return (EXIT_FAILURE);
	}
	data->mlx->img_data_E.pixels = mlx_get_data_addr(
		data->mlx->E_img, &data->mlx->img_data_E.bits_per_pixel,
		&data->mlx->img_data_E.line_len, &data->mlx->img_data_E.endian);
	return (EXIT_SUCCESS);
}

int	image_west(t_data *data, int x)
{
	data->mlx->W_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->W_text,
		&x, &x);
	if (data->mlx->W_img == NULL)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->N_img);
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->S_img);
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->E_img);
		return (EXIT_FAILURE);
	}
	data->mlx->img_data_W.pixels = mlx_get_data_addr(
		data->mlx->W_img, &data->mlx->img_data_W.bits_per_pixel,
		&data->mlx->img_data_W.line_len, &data->mlx->img_data_W.endian);
	return (EXIT_SUCCESS);
}
