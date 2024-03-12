/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:51:10 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/10 13:28:43 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_arg_name(char *argv)
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

char	*get_file(char *argv)
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
