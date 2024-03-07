/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:33:12 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/07 19:03:00 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	*text_path = ft_substr(texture, i, j - i); //hay que liberar;
	if (*text_path == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	set_texture(char *texture, t_data *data)
{
	is_white_space(&texture);
	if (!ft_strncmp(texture, "NO", 2))
		return (charge_image(texture, &data->N_text));
	else if (!ft_strncmp(texture, "SO", 2))
		return (charge_image(texture, &data->S_text));
	else if (!ft_strncmp(texture, "WE", 2))
		return (charge_image(texture, &data->W_text));
	else if (!ft_strncmp(texture, "EA", 2))
		return (charge_image(texture, &data->E_text));
	return (EXIT_SUCCESS);
}