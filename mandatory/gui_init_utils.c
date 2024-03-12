/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:33:12 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/12 19:21:09 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_free(t_data *data)
{
	if (!data->n_text)
		free(data->n_text);
	if (!data->s_text)
		free(data->s_text);
	if (!data->w_text)
		free(data->w_text);
	if (!data->e_text)
		free(data->e_text);
}

void	init_textures(t_data *data)
{
	data->n_text = NULL;
	data->s_text = NULL;
	data->w_text = NULL;
	data->e_text = NULL;
}

static int	charge_image(char *texture, char **text_path)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (texture[i] && texture[i] == ' ')
		i++;
	while (texture[i] && texture[i] != ' ')
		i++;
	while (texture[i] && texture[i] == ' ')
		i++;
	j = i;
	while (texture[j])
		j++;
	*text_path = ft_substr(texture, i, j - i);
	if (*text_path == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	set_texture(char *texture, t_data *data)
{
	is_white_space(&texture);
	if (!ft_strncmp(texture, "NO", 2))
		return (charge_image(texture, &data->n_text));
	else if (!ft_strncmp(texture, "SO", 2))
		return (charge_image(texture, &data->s_text));
	else if (!ft_strncmp(texture, "WE", 2))
		return (charge_image(texture, &data->w_text));
	else if (!ft_strncmp(texture, "EA", 2))
		return (charge_image(texture, &data->e_text));
	return (EXIT_SUCCESS);
}
