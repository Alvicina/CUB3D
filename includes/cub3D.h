/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:05:05 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/23 11:42:43 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_data{
	char	*file;
	char	**map_spec;
	char	**textures;
	char	**map_only;
}	t_data;

// modulo utils_copy_file_map_position
void	ft_message(char *str);
char	*replace_chars(char *str, char *to_find, char replace);
int		check_number_args(int argc);
void	ft_free_pointer_array(char **str);

// modulo check_map_position
int	get_data(t_data *data);
int	is_map_line(char *set, char *line_to_check);

// modulo split_map_specifications
int	split_map_specifications(t_data *data);

// modulo specifications_checker
int	specs_checker(t_data *data);

// modulo specifications_checker_utils
int		spec_valid_check(t_data *data);
void	is_white_space(char **str);

// modulo color_validation
int	check_colors(char *str);

// modulo check_file_last_part
int	check_last_part_file(t_data	*data);


#endif