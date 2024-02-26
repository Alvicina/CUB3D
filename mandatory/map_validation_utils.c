/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:10 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/26 13:28:25 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	what_around_whitespace(t_data *data, size_t i, size_t j)
{
	if (i == 0)
	{
		if (j == 0)
		{
			if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
			|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' '))
				return (EXIT_FAILURE);
		}
		else
		{
			if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
			|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' ')
			|| (data->map_only[i][j - 1] != '1' && data->map_only[i][j - 1] != ' '))
				return (EXIT_FAILURE);	
		}
	}
	else
	{
		if (j == 0)
		{
			if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
			|| (data->map_only[i - 1][j] != '1' && data->map_only[i - 1][j] != ' ')
			|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' '))
				return (EXIT_FAILURE);
		}
		else
		{
			printf("j: %zu i: %zu\n", j, i);
			if ((data->map_only[i + 1][j] != '1' && data->map_only[i + 1][j] != ' ')
			|| (data->map_only[i - 1][j] != '1' && data->map_only[i - 1][j] != ' ')
			|| (data->map_only[i][j + 1] != '1' && data->map_only[i][j + 1] != ' ')
			|| (data->map_only[i][j - 1] != '1' && data->map_only[i][j - 1] != ' '))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
