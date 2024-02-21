/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifications_checker_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:03:29 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/21 13:20:50 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	check_path(char *str)
{
	if (open(str, O_RDONLY) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	find_texture_path_for_valid(char *str)
{
	is_white_space(&str);
	if (!ft_strncmp(str, "F", 1) || (!ft_strncmp(str, "C", 1)))
	{
		if (check_colors(str))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	while (*str != ' ')
		str++;
	if (!str)
		return (EXIT_FAILURE);
	is_white_space(&str);
	if (!str)
		return (EXIT_FAILURE);
	if (check_path(str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	spec_valid_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->textures[i])
	{
		if (find_texture_path_for_valid(data->textures[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	is_white_space(char **str)
{
	while (*str)
	{
		if (**str == ' ')
			(*str)++;
		else
			break ;
	}
}
