/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:35:35 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/08 19:23:14 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	init_window(t_mlx *mlx);
static int	init_img(t_mlx *mlx);
static int	charge_textures(t_data *data);
static int	get_addr(t_data *data, int x);

int	init_gui(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (data->mlx == NULL)
		return (EXIT_FAILURE);
	data->mlx->mlx_ptr = mlx_init();
	if (data->mlx->mlx_ptr == NULL)
	{
		free(data->mlx);
		return (EXIT_FAILURE);
	}
	if (init_window(data->mlx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_img(data->mlx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (charge_textures(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_window(t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->mlx_ptr);
		free(mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_img(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img_ptr == NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		free(mlx->mlx_ptr);
		free(mlx);
		return (EXIT_FAILURE);
	}
	mlx->img_data.pixels = mlx_get_data_addr(
			mlx->img_ptr,
			&mlx->img_data.bits_per_pixel,
			&mlx->img_data.line_len,
			&mlx->img_data.endian);
	return (EXIT_SUCCESS);
}

static int	charge_textures(t_data *data)
{
	size_t	i;
	int		x;
	
	x = 64;
	i = 0;
	while (data->textures[i])
	{
		if (set_texture(data->textures[i], data))
			return (EXIT_FAILURE);
		i++;
	}
	ft_free_pointer_array(data->textures);
	if (get_addr(data, x))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);	
}

static int	get_addr(t_data *data, int x)
{
	data->mlx->N_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->N_text,
		&x, &x);
	data->mlx->img_data_N.pixels = mlx_get_data_addr(
		data->mlx->N_img, 
		&data->mlx->img_data_N.bits_per_pixel,
		&data->mlx->img_data_N.line_len,
		&data->mlx->img_data_N.endian);
	data->mlx->S_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->S_text,
		&x, &x);
	data->mlx->img_data_S.pixels = mlx_get_data_addr(data->mlx->S_img, 
		&data->mlx->img_data_S.bits_per_pixel, &data->mlx->img_data_S.line_len, 
		&data->mlx->img_data_S.endian);
	data->mlx->E_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->E_text,
		&x, &x);
	data->mlx->img_data_E.pixels = mlx_get_data_addr(data->mlx->E_img, 
		&data->mlx->img_data_E.bits_per_pixel, &data->mlx->img_data_E.line_len, 
		&data->mlx->img_data_E.endian);
	data->mlx->W_img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->W_text,
		&x, &x);
	data->mlx->img_data_W.pixels = mlx_get_data_addr(data->mlx->W_img, 
		&data->mlx->img_data_W.bits_per_pixel, &data->mlx->img_data_W.line_len, 
		&data->mlx->img_data_W.endian);
	return (EXIT_SUCCESS);
}
