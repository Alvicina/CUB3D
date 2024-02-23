/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:34 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/23 12:38:07 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_map_line(char *set, char *line_to_check)
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

	i = 0;
	while (data->map_spec[i])
	{
		if (data->map_spec[i] && is_map_line(set, data->map_spec[i]))
		{
			if (i < 6)
				return (EXIT_FAILURE);
			if (i == count)
				return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

static int	check_map_position(t_data *data)
{
	char	*set;
	size_t	count;

	set = "10N SEW";
	count = 0;
	while (data->map_spec[count])
		count++;
	count = count - 1;
	if (!loop_for_map_pos(data, set, count))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	get_data(t_data *data)
{
	data->map_spec = ft_split(data->file, '\n');
	if (data->map_spec == NULL)
	{
		free(data->file);
		return (perror("Split malloc error, could not check map"),
			EXIT_FAILURE);
	}
	if (check_map_position(data))
		return (ft_message("Error\nMap not in last position\n"),
			free(data->file), EXIT_FAILURE);
	if (split_map_specifications(data))
		return (EXIT_FAILURE);
	if (check_last_part_file(data))
	{
		free(data->file);
		return (EXIT_FAILURE);
	}
	free(data->file);
	return (EXIT_SUCCESS);
}
