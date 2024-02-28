/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:28:26 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/28 16:36:55 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_left_close(t_data *data, int j, int i)
{
	if (data->map_only[i][j] && data->map_only[i][j] != '1')
		return (EXIT_FAILURE);
	while (data->map_only[i][j])
			j++;
	j = j - 1;
	while (j >= 0)
	{
		while (data->map_only[i][j] == ' ')
			j--;
		if (data->map_only[i][j] != '1')
			return (EXIT_FAILURE);
		break;
	}
	return (EXIT_SUCCESS);
}

int	check_player(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	flag = 0;
	while (data->map_only[i])
	{
		j = 0;
		while (data->map_only[i][j])
		{
			if (!ft_comp(data->map_only[i][j], "NSEW"))
			{
				if (flag == 0)
					flag++;
				else
					return (ft_message("Error\nPlayer position dup"), 1);
			}
			j++;
		}
		i++;
	}
	if (flag == 0)
		return (ft_message("Error\nNo player position"), 1);
	return (0);
}
