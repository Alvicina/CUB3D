/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:10 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/27 10:58:02 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	what_around_whitespace(t_data *data, size_t i, size_t j)
{
	size_t	map_lines;

	map_lines = 0;
	while (data->map_only[map_lines])
		map_lines++;
	if (i == 0)
	{
		/*if (j > ft_strlen(data->map_only[i + 1]))
			return (EXIT_SUCCESS);*/
		if (j == 0)
		{
			if (j < ft_strlen(data->map_only[i]) - 1 && i < map_lines - 1)
			{
				if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
				|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' '))
					return (EXIT_FAILURE);
			}
		}
		else
		{
			if (j < ft_strlen(data->map_only[i]) - 1 && i < map_lines - 1)
			{
				if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
				|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' ')
				|| (data->map_only[i][j - 1] != '1' && data->map_only[i][j - 1] != ' '))
					return (EXIT_FAILURE);
			}
		}
	}
	else
	{
		if (j == 0)
		{
			if (j < ft_strlen(data->map_only[i]) - 1 && i < map_lines - 1)
			{
				if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
				|| (data->map_only[i - 1][j] != '1' && data->map_only[i - 1][j] != ' ')
				|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' '))
					return (EXIT_FAILURE);
			}
		}
		else
		{
			printf("j: %zu i: %zu\n", j, i);
			printf("ft_strlen: %zu map_lines: %zu\n", ft_strlen(data->map_only[i]), map_lines);
			if (j < ft_strlen(data->map_only[i]) - 1 && i < map_lines - 1)
			{
				if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
				|| (data->map_only[i - 1][j] != '1' && data->map_only[i - 1][j] != ' ')
				|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' ')
				|| (data->map_only[i][j - 1] != '1' && data->map_only[i][j - 1] != ' '))
				{
					
					return (EXIT_FAILURE);
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	check_non_lead_whitespace(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map_only[i])
	{
		j = 0;
		while (data->map_only[i][j])
		{
			if (data->map_only[i][j] == ' ')
			{
				if (what_around_whitespace(data, i, j))
				{
					printf("i: %zu j: %zu  s: %s c: %c\n", i, j, data->map_only[i], data->map_only[i][j]);
					return (EXIT_FAILURE);
				}	
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
