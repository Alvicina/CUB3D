/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_last_part.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:41:43 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/23 12:14:15 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	check_if_double_jump(t_data *data, ssize_t i)
{
	while (data->file[i])
	{
		if (data->file[i] == '\n')
		{
			i++;
			while (data->file[i] == ' ')
				i++;
			if (data->file[i] == '\n')
				return (-1);
		}
		if (data->file[i])
			i++;
	}
	return (i);
}

int	check_last_part_file(t_data	*data)
{
	ssize_t	i;

	i = 0;
	while (data->file[i])
	{
		while (data->file[i] == ' ')
			i++;
		if (data->file[i] != '1' && data->file[i] != '0')
		{
			while (data->file[i] != '\n' && data->file[i])
				i++;
			i++;
		}
		else
		{
			i = check_if_double_jump(data, i);
			if (i == -1)
				return (ft_message("Error\nMap not in las position\n"),
					EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
