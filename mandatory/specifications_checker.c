/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifications_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:36:27 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/20 19:04:53 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	checker_name(char *str)
{
		if (!ft_strncmp(str, "NO", 2))
			return (EXIT_SUCCESS);
		else if (!ft_strncmp(str, "SO", 2))
			return (EXIT_SUCCESS);
		else if (!ft_strncmp(str, "WE", 2))
			return (EXIT_SUCCESS);
		else if (!ft_strncmp(str, "EA", 2))
			return (EXIT_SUCCESS);
		else if (!ft_strncmp(str, "F", 1))
			return (EXIT_SUCCESS);
		else if (!ft_strncmp(str, "C", 1))
			return (EXIT_SUCCESS);
		else
			return (EXIT_FAILURE);
}

static int	spec_name_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->textures[i])
	{
		if (checker_name(data->textures[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	spec_amount_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->textures[i])
		i++;
	if (i == 6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	texture_checker(t_data *data)
{
	if (spec_amount_check(data))
		return (ft_message("Error\n"), ft_message("missing spec\n"),
			EXIT_FAILURE);
	if (spec_name_check(data))
		return (ft_message("Error\n"), ft_message("spec name \n"),
			EXIT_FAILURE);
	if (spec_valid_check(data))
		return (ft_message("Error\n"), ft_message("spec value / path \n"),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	specs_checker(t_data *data)
{
	if (texture_checker(data))
		return (EXIT_FAILURE);
	/*if (map_checker(data))
		return (EXIT_FAILURE);*/
	return (EXIT_SUCCESS);
}