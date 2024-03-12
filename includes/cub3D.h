/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:05:05 by alvicina          #+#    #+#             */
/*   Updated: 2024/03/12 19:51:20 by afidalgo         ###   ########.fr       */
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
# define TEXTURE_LEN 64
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

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17

# define MOVE_SPEED 10
# define TURN_SPEED 5

# define PI 3.1415926535897932384626

typedef enum e_direction
{
	LEFT = 1,
	RIGHT,
	FORWARD,
	BACKWARD
}	t_direction;

typedef struct s_player
{
	int			x;
	int			y;
	int			dir;
	t_direction	directions[2];
	t_direction	movement[4];
}				t_player;

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
	void		*n_img;
	t_img_data	img_data_n;
	void		*s_img;
	t_img_data	img_data_s;
	void		*e_img;
	t_img_data	img_data_e;
	void		*w_img;
	t_img_data	img_data_w;
}				t_mlx;

typedef struct s_data
{
	char		*file;
	char		**map_spec;
	char		**textures;
	char		**map_only;
	t_player	*player;
	t_mlx		*mlx;
	char		*n_text;
	char		*s_text;
	char		*e_text;
	char		*w_text;
	int			floor;
	int			ceiling;
}				t_data;

typedef enum e_texture_dir
{
	NORTH = 1,
	EAST,
	SOUTH,
	WEST
}	t_texture_dir;

typedef struct s_wall
{
	double			x;
	double			y;
	t_texture_dir	dir;
	double			height;
	int				offset;
	t_img_data		*texture;
}					t_wall;

typedef struct s_position
{
	double	distance_top;
	double	distance_bottom;
	double	distance_left;
	double	distance_right;
	double	top_right_angle;
	double	top_left_angle;
	double	bottom_left_angle;
	double	bottom_right_angle;
	double	dir_deg;
	double	dir_rad;
	double	x;
	double	y;
}			t_position;

// copy_fie.c
int		check_arg_name(char *argv);
char	*get_file(char *argv);

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
int		check_colors(char *str, int *color);

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
int		get_addr(t_data *data, int x);

// gui_event_handler.c
void	set_event_hooks(t_data *data);

// player_init.c
int		init_player(t_data *data);

// player_movement.c
void	move(t_data *data, t_direction dir);

// player_direction.c
void	turn_pov(t_data *data, t_direction dir);
void	set_direction(t_data *data, t_direction dir);
void	unset_direction(t_data *data, t_direction dir);

// map_walls.c
int		is_next_step_a_wall(t_data *data, double dir_rad);
t_wall	get_next_wall(t_data *data, double x, double y, double dir_deg);
int		is_coord_a_wall(t_data *data, double x, double y);
double	get_distance_to_wall(t_data *data, t_wall *wall, double dir_rad);

// map_wall_dir.c
void	get_wall_west(t_wall *wall, t_position *position);
void	get_wall_east(t_wall *wall, t_position *position);
void	get_wall_south(t_wall *wall, t_position *position);
void	get_wall_north(t_wall *wall, t_position *position);
void	get_wall_on_square_junction(t_wall *wall, t_position *position);

// map_render.c
int		render(t_data *data);
void	render_map(t_data *data);

// map_render_walls.c
void	render_walls(t_data *data);

// map_position.c
void	get_position(t_position *position, double x, double y, double dir_deg);

// mlx_utils.c
void	draw_pixel(t_mlx *mlx, int x, int y, int color);

// utils.c
int		terminate(t_data *data);
double	deg2rad(double deg);
double	rad2deg(double rad);
void	free_massive(t_data *data);

// gui_init_utils.c 
int		set_texture(char *texture, t_data *data);
int		alloc_memory_mlx(t_data *data);
void	check_free(t_data *data);
void	init_textures(t_data *data);

// get_addr_utils.c
int		image_north(t_data *data, int x);
int		image_south(t_data *data, int x);
int		image_east(t_data *data, int x);
int		image_west(t_data *data, int x);

#endif
