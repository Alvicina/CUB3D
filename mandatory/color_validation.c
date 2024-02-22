/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:20:26 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/22 11:19:01 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	value_valid(char *str, size_t *flag, char **num, int *num_atoi)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == ',')
			i++;
		j = i;
		while (str[j] >= 48 && str[j] <= 57)
			j++;
		if (str[i])
			(*flag)++;
		if (*flag > 3)
			return (EXIT_FAILURE);
		*num = ft_substr(str, i, j - i);
		if (*num == NULL)
			return (perror(0), EXIT_FAILURE);
		*num_atoi = ft_atoi(*num);
		if (*num_atoi > 255)
			return (EXIT_FAILURE);
		free(*num);
		i = j;
	}
	return (EXIT_SUCCESS);
}

static int	chars_valid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != ',' && !(str[i] >= 48 && str[i] <= 57))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	is_color_valid(char *str)
{
	size_t	flag;
	char	*num;
	int		num_atoi;

	flag = 0;
	num = NULL;
	num_atoi = 0;
	if (chars_valid(str))
		return (EXIT_FAILURE);
	if (value_valid(str, &flag, &num, &num_atoi))
		return (EXIT_FAILURE);
	if (flag != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_colors(char *str)
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
