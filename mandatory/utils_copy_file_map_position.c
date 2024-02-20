/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_copy_file_map_position.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:49:28 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/20 11:21:52 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_free_pointer_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_number_args(int argc)
{
	if (argc != 2)
	{
		if (argc == 1)
			ft_message("Map not found, please intro map\n");
		else if (argc > 2)
			ft_message("Incorrect number of arguments\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_message(char *str)
{
	ft_putstr_fd(str, 2);
}

char	*replace_chars(char *str, char *to_find, char replace)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j])
		{
			if (str[i] == to_find[j])
				str[i] = replace;
			j++;
		}
		i++;
	}
	return (str);
}
