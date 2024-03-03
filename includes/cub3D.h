/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:05:05 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/03 09:51:32 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 750
# define TILE_LEN 64
# define POV_DEG 60

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define MOVE_SPEED 10
# define TURN_SPEED 5

# define PI 3.14159265359

typedef struct s_player
{
	int	x;
	int	y;
	int	dir;
}		t_player;

typedef struct s_img_data
{
	char	*pixels;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img_data;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img_data	img_data;
	char		**map;
}				t_mlx;

typedef struct s_data
{
	char		*file;
	char		**map_spec;
	char		**textures;
	char		**map_only;
	t_player	*player;
	t_mlx		*mlx;
}				t_data;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

// modulo utils_copy_file_map_position
void	ft_message(char *str);
char	*replace_chars(char *str, char *to_find, char replace);
int		check_number_args(int argc);
void	ft_free_pointer_array(char **str);

// modulo check_map_position
int		get_data(t_data *data);
int		is_map_line(char *set, char *line_to_check);

// modulo split_map_specifications
int		split_map_specifications(t_data *data);

// modulo specifications_checker
int		specs_checker(t_data *data);

// modulo specifications_checker_utils
int		spec_valid_check(t_data *data);
void	is_white_space(char **str);

// modulo color_validation
int		check_colors(char *str);

// modulo check_file_last_part
int		check_last_part_file(t_data	*data);

// modulo map_validation
int		map_checker(t_data *data);

// modulo map_validation_utils
int		what_around_whitespace(t_data *data, int i, size_t j, int lines);
int		check_non_lead_whitespace(t_data *data);
int		ft_comp(char c, char *set);

// modulo make_square_map
int		make_map_square(t_data *data);

// modulo check_player_and_left
int		check_player(t_data *data);
int		check_left_close(t_data *data, int j, int i);
// gui_init.c
int		init_gui(t_data *data);

// gui_event_handler.c
void	set_event_hooks(t_data *data);

// player_init.c
int		init_player(t_data *data);

// player_movement.c
void	look_left(t_player *player);
void	look_right(t_player *player);
void	move(t_data *data, double dir_rad);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
int		is_next_step_a_wall(t_data *data, double dir_rad);

// utils.c
int		terminate(t_data *data);
double	deg2rad(int deg);

#endif