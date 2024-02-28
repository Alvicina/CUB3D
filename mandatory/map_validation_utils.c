/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:10 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/27 15:38:52 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_comp(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

static int	first_row(t_data *data, int i, size_t j, int lines)
{
	if (j == 0)
	{
		if (j < ft_strlen(data->map_only[i]) - 1 && i < lines - 1)
		{
			if (ft_comp(data->map_only[i + 1][j], "1 -")
			|| ft_comp(data->map_only[i][j + 1], "1 -"))
				return (EXIT_FAILURE);
		}
	}
	else
	{
		if (j < ft_strlen(data->map_only[i]) - 1 && i < lines - 1)
		{
			if (ft_comp(data->map_only[i + 1][j], "1 -")
			|| ft_comp(data->map_only[i][j + 1], "1 -")
			|| ft_comp(data->map_only[i][j - 1], "1 -"))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	other_rows(t_data *data, int i, size_t j, int lines)
{
	if (j == 0)
	{
		if (j < ft_strlen(data->map_only[i]) - 1 && i < lines - 1)
		{
			if (ft_comp(data->map_only[i + 1][j], "1 -")
			|| ft_comp(data->map_only[i - 1][j], "1 -")
			|| ft_comp(data->map_only[i][j + 1], "1 -"))
				return (EXIT_FAILURE);
		}
	}
	else
	{
		if (j < ft_strlen(data->map_only[i]) - 1 && i < lines - 1)
		{
			if (ft_comp(data->map_only[i + 1][j], "1 -")
			|| ft_comp(data->map_only[i - 1][j], "1 -")
			|| ft_comp(data->map_only[i][j + 1], "1 -")
			|| ft_comp(data->map_only[i][j + 1], "1 -"))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	what_around_whitespace(t_data *data, int i, size_t j, int lines)
{
	if (i == 0)
	{
		if (first_row(data, i, j, lines))
			return (EXIT_FAILURE);
	}
	else
	{
		if (other_rows(data, i, j, lines))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_non_lead_whitespace(t_data *data)
{
	int		i;
	size_t	j;
	int		map_lines;

	map_lines = 0;
	while (data->map_only[map_lines])
		map_lines++;
	i = 0;
	while (data->map_only[i])
	{
		j = 0;
		while (data->map_only[i][j])
		{
			if (data->map_only[i][j] == ' ')
			{
				if (what_around_whitespace(data, i, j, map_lines))
					return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
