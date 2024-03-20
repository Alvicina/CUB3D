/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:00:34 by afidalgo          #+#    #+#             */
/*   Updated: 2024/03/18 09:36:40 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	init_game(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

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
	if (init_game(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_game(t_data *data)
{
	if (init_gui(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	set_event_hooks(data);
	if (init_player(data) == EXIT_FAILURE)
	{
		free_massive(data);
		return (EXIT_FAILURE);
	}
	render_map(data);
	mlx_loop(data->mlx->mlx_ptr);
	return (EXIT_SUCCESS);
}
