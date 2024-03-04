/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_copy_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:51:10 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/04 15:59:09 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	check_arg_name(char *argv)
{
	size_t	i;

	i = ft_strlen(argv) - 1;
	if (argv[i] != 'b' || argv[i - 1] != 'u' || argv[i - 2] != 'c'
		|| argv[i - 3] != '.')
		return (ft_message("Incorrect file name\n"), EXIT_FAILURE);
	while (i > 0 && argv[i] != '/')
		i--;
	if (ft_strlen(&argv[i]) <= 5)
		return (ft_message("Incorrect file name\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	read_file(int fd)
{
	int		size;
	int		temp;
	char	buf[50];

	size = 0;
	temp = 1;
	while (temp)
	{
		temp = read(fd, buf, 50);
		if (temp == -1)
			return (1);
		size = size + temp;
	}
	close(fd);
	return (size);
}

static char	*copy_file(char *argv, int size)
{
	char	*file;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file = malloc(sizeof(char) * (size + 1));
	if (file == NULL)
		return (NULL);
	if (read(fd, file, size) == -1)
	{
		free(file);
		return (NULL);
	}
	file[size] = 0;
	return (file);
}

static char	*get_file(char *argv)
{
	int		fd;
	int		size;
	char	*file;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return ((perror("Could not open file"), NULL));
	size = read_file(fd);
	if (size == -1)
		return ((perror("Could not read file"), NULL));
	file = copy_file(argv, size);
	if (file == NULL)
		return ((perror("Could not copy file"), NULL));
	return (file);
}

int	main(int argc, char **argv)
{
	t_data	data;
	// double distance;
	// double i;
	
	if (check_number_args(argc))
		return (EXIT_FAILURE);
	if (check_arg_name(argv[1]))
		return (EXIT_FAILURE);
	data.file = get_file(argv[1]);
	if (data.file == NULL)
		return (EXIT_FAILURE);
	data.file = replace_chars(data.file, "\t\v\f\r", ' ');
	if (get_data(&data))
	{
		ft_free_pointer_array(data.map_spec);
		return (EXIT_FAILURE);
	}
	if (init_gui(&data) == EXIT_FAILURE)
	{
		ft_free_pointer_array(data.textures);
		ft_free_pointer_array(data.map_only);
		ft_free_pointer_array(data.map_spec);
		return (EXIT_FAILURE);
	}
	set_event_hooks(&data);
	init_player(&data);
	render_map(&data);

	// i = data.player->dir + 15;
	// while (i >= data.player->dir - 15)
	// {
	// 	distance = get_distance_to_wall(&data, data.player->x, data.player->y, i);
	// 	printf("distance = %f dir = %f\n", distance, i);
	// 	i--;
	// }
	// distance = get_distance_to_wall(&data, data.player->x, data.player->y, data.player->dir - 3, 0);
	// printf("distance = %f dir = %d\n\n\n", distance, data.player->dir - 3);
	// distance = get_distance_to_wall(&data, data.player->x, data.player->y, 89.96, 0);
	// printf("distance = %f dir = %f\n\n\n", distance, 89.96);
	// distance = get_distance_to_wall(&data, data.player->x, data.player->y, data.player->dir + 3, 0);
	// printf("distance = %f dir = %d\n\n\n", distance, data.player->dir + 3);

	mlx_loop(data.mlx->mlx_ptr);

	return (EXIT_SUCCESS);
}
