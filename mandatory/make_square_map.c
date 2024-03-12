/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:35:05 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/09 12:51:31 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	get_new_map(t_data *data, char **new, size_t max_line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (new[i])
	{
		j = 0;
		while (data->map_only[i][j])
		{
			new[i][j] = data->map_only[i][j];
			j++;
		}
		while (j < max_line)
		{
			new[i][j] = '-';
			j++;
		}
		new[i][j] = 0;
		i++;
	}
	ft_free_pointer_array(data->map_only);
	data->map_only = new;
}

static int	get_biggest_line(t_data *data)
{
	size_t	i;
	size_t	max_line;

	i = 0;
	max_line = 0;
	while (data->map_only[i])
	{
		if (max_line < ft_strlen(data->map_only[i]))
			max_line = ft_strlen(data->map_only[i]);
		i++;
	}
	return (max_line);
}

int	make_map_square(t_data *data)
{
	ssize_t	i;
	size_t	max_line;
	char	**square_map;

	i = 0;
	while (data->map_only[i])
		i++;
	max_line = get_biggest_line(data);
	square_map = malloc(sizeof(char *) * (i + 1));
	if (square_map == NULL)
		return (EXIT_FAILURE);
	square_map[i] = 0;
	i = i - 1;
	while (i >= 0)
	{
		square_map[i] = malloc(sizeof(char) * (max_line + 1));
		if (square_map[i] == NULL)
			return (ft_free_pointer_array(square_map), EXIT_FAILURE);
		i--;
	}
	get_new_map(data, square_map, max_line);
	return (EXIT_SUCCESS);
}
