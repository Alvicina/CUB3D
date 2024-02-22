/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_map_specifications.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:28:39 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/22 15:50:44 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	get_map(t_data *data)
{
	size_t	i;
	size_t	j;
	char	*set;

	i = 0;
	set = "10N SEW";
	while (data->map_spec[i] && !is_map_line(set, data->map_spec[i]))
		i++;
	j = 0;
	while (data->map_spec[i] && is_map_line(set, data->map_spec[i]))
	{
		data->map_only[j] = ft_strdup(data->map_spec[i]);
		if (data->map_only[j] == NULL)
			return (EXIT_FAILURE);
		//printf("%s\n", data->map_only[j]);
		i++;
		j++;
	}
	data->map_only[j] = 0;
	return (EXIT_SUCCESS);
}

static int	get_textures(t_data *data)
{
	size_t	i;
	char	*set;
	
	i = 0;
	set = "10N SEW";
	while (data->map_spec[i] && !is_map_line(set, data->map_spec[i]))
	{
		data->textures[i] = ft_strdup(data->map_spec[i]);
		if (data->textures[i] == NULL)
			return (EXIT_FAILURE);
		//printf("%s\n", data->textures[i]);
		i++;
	}
	data->textures[i] = 0;
	return (EXIT_SUCCESS);
}

static int	alloc_memory_for_specs(t_data *data)
{
	size_t	count_map_lines;
	char	*set;
	size_t	i;
	
	set = "10N SEW";
	count_map_lines = 0;
	i = 0;
	while (data->map_spec[i])
	{
		if (data->map_spec[i] && !is_map_line(set, data->map_spec[i]))
			i++;
		else
			break ;
	}
	data->textures = malloc(sizeof(char *) * (i + 1));
	if (data->textures == NULL)
		return (EXIT_FAILURE);
	count_map_lines = i;
	while (data->map_spec[count_map_lines] && is_map_line(set, data->map_spec[count_map_lines]))
		count_map_lines++;
	data->map_only = malloc(sizeof(char *) * (count_map_lines + 1));
	if (data->map_only == NULL)
		return (free(data->textures), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	split_map_specifications(t_data *data)
{
	if (alloc_memory_for_specs(data))
		return (perror("Malloc error when splitting specs"), EXIT_FAILURE);
	if (get_textures(data))
		return (perror("Malloc error when splitting specs"), EXIT_FAILURE);
	if (get_map(data))
	{
		ft_free_pointer_array(data->textures);
		return (perror("Malloc error when splitting specs"), EXIT_FAILURE);
	}
	if (specs_checker(data))
	{
		ft_free_pointer_array(data->textures);
		ft_free_pointer_array(data->map_only);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
