/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:34 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/19 16:33:35 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	is_map_line(char *set, char *line_to_check)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (line_to_check[i])
	{
		j = 0;
		while (set[j])
		{
			if (line_to_check[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			return (0);
		i++;
	}
	return (1);
}

static int	loop_for_map_pos(t_data *data, char *set, size_t count)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (data->map_spec[i])
	{
		j = 0;
		while (data->map_spec[i][j] && data->map_spec[i][j] == ' ')
			j++;
		while (data->map_spec[i] && is_map_line(set, data->map_spec[i]))
		{
			if (i < 6)
				return (0);
			i++;
			if (i == count)
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_map_position(t_data *data)
{
	char	*set;
	size_t	count;
	
	set = "10NSEW";
	count = 0;
	while (data->map_spec[count])
		count++;
	if (loop_for_map_pos(data, set, count))
		return (1);
	return (0);
}

char	**get_data(t_data *data)
{
	size_t	i;

	i = 0;
	data->map_spec = ft_split(data->file, '\n');
	if (data->map_spec == NULL)
	{
		free(data->file);
		return (ft_message("Split malloc error, could not check map"), NULL);
	}
	free(data->file);
	if (!check_map_position(data))
		return (ft_message("Error\n"), ft_message("Map not in last position\n"), NULL);
	return (data->map_spec);
}
