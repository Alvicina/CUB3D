/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:05:05 by alvicina          #+#    #+#             */
/*   Updated: 2024/02/19 16:38:49 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include <unistd.h>

typedef struct s_data{
	char	*file;
	char	**map_spec;
}	t_data;

// modulo utils
void	ft_message(char *str);
char	*replace_chars(char *str, char *to_find, char replace);
int		check_number_args(int argc);
void	ft_free_pointer_array(char **str);

// modulo getter_data
char	**get_data(t_data *data);



#endif