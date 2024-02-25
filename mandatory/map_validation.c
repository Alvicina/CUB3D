/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:54:40 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/25 12:02:10 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	return (EXIT_SUCCESS);
	
}