/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:54:40 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/26 15:57:02 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	check_non_lead_whitespace(t_data *data)
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

static int	left_right_close(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map_only[i])
	{	
		j = 0;
		while (data->map_only[i][j] == ' ')
			j++;
		if (!data->map_only[i][j] || data->map_only[i][j] != '1')
			return (EXIT_FAILURE);
		while (data->map_only[i][j])
			j++;
		j = j - 1;
		while (j >= 0 && data->map_only[i][j] && data->map_only[i][j] == ' ')
				j--;
		if (j == 0 || data->map_only[i][j] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	top_bottom_close(t_data *data)
{
	size_t	first;
	size_t	final;
	size_t	j;

	j = 0;
	first = 0;
	final = 0;
	while (data->map_only[final] && data->map_only[final + 1])
		final++;
	while (data->map_only[first][j])
	{
		if (data->map_only[first][j] != '1' && data->map_only[first][j] != ' ')
			return (EXIT_FAILURE);
		j++;
	}
	j = 0;
	while (data->map_only[final][j])
	{
		if (data->map_only[final][j] != '1' && data->map_only[final][j] != ' ')
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}

static int	only_map_chars(t_data *data)
{
	size_t	i;
	char	*set;

	set = "10N SEW";
	i = 0;
	while (data->map_only[i])
	{
		if (!is_map_line(set, data->map_only[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	map_checker(t_data *data)
{
	if (only_map_chars(data))
		return (ft_message("Error\nInvalid char in map\n"), EXIT_FAILURE);
	if (top_bottom_close(data))
		return (ft_message("Error\nIncorrect map border\n"), EXIT_FAILURE);
	if (left_right_close(data))
		return (ft_message("Error\nIncorrect map border\n"), EXIT_FAILURE);
	if (check_non_lead_whitespace(data))
		return (ft_message("Error\nIncorrect layout\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
	
}