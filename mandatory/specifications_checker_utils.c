/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifications_checker_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:03:29 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/21 13:05:51 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_color_valid(char *str)
{
	size_t	i;
	size_t	j;
	size_t	flag;
	int		num_atoi;
	char	*num;

	i = 0;
	flag = 0;
	num_atoi = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != ',' && !(str[i] >= 48 && str[i] <= 57))
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == ',')
			i++;
		j = i;
		while (str[j] >= 48 && str[j] <= 57)
			j++;
		flag++;
		if (flag > 3)
			return (EXIT_FAILURE);
		num = ft_substr(str, i, j - i);
		if (num == NULL)
			return (perror(0), EXIT_FAILURE);
		num_atoi = ft_atoi(num);
		if (num_atoi > 255)
			return (EXIT_FAILURE);
		ft_printf("%s\n", num);
		free(num);
		i = j;
	}
	if (flag != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_colors(char *str)
{
	while (*str != ' ')
		str++;
	if (!str)
		return (EXIT_FAILURE);
	is_white_space(&str);
	if (!str)
		return (EXIT_FAILURE);
	if (is_color_valid(str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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
