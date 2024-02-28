/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:54:40 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/28 16:37:50 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	left_right_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_only[i])
	{
		j = 0;
		while (data->map_only[i][j] == ' ')
			j++;
		if (!data->map_only[i][j])
			i++;
		else
		{
			if (check_left_close(data, j, i))
				return (EXIT_FAILURE);
			i++;
		}
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

static int	map_size(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map_only[i])
		i++;
	if (i < 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	map_checker(t_data *data)
{
	if (map_size(data))
		return (ft_message("Error\nMap too small\n"), EXIT_FAILURE);
	if (only_map_chars(data))
		return (ft_message("Error\nInvalid char in map\n"), EXIT_FAILURE);
	if (top_bottom_close(data))
		return (ft_message("Error\nIncorrect map border\n"), EXIT_FAILURE);
	if (left_right_close(data))
		return (ft_message("Error\nIncorrect map border\n"), EXIT_FAILURE);
	if (make_map_square(data))
		return (perror("while making map square\n"), EXIT_FAILURE);
	if (check_non_lead_whitespace(data))
		return (ft_message("Error\nIncorrect layout\n"), EXIT_FAILURE);
	if (check_player(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
