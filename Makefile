# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 16:37:55 by alvicina          #+#    #+#              #
#    Updated: 2024/02/23 12:35:52 by alvicina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP

NAME            = cub3D
CC              = gcc
RM              = rm -rf
FLAGS           = -Wall -Wextra -Werror -Ilibft -Imlx -g3 #-fsanitize=address

#FILES AND PATH

HEADER_SRCS = cub3D.h
HEADER_DIR  = includes/
HEADER      = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS  = main_copy_file.c utils_copy_file_map_position.c check_map_position.c \
			  split_map_specifications.c specifications_checker.c specifications_checker_utils.c \
			  color_validation.c check_file_last_part.c \

MPATH_DIR   = mandatory/
MPATH       = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M       = $(MPATH:.c=.o)

BPATH_SRCS  = 
BPATH       = $(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B       = $(BPATH:.c=.o)

#COMMANDS
all:        lib $(NAME)

$(NAME):    $(OBJ_M)
		    @$(CC) $(FLAGS) $(OBJ_M) -Llibft -lft -Lmlx -lmlx -framework OpenGl -framework AppKit -o $(NAME) 

%.o: %.c $(HEADER) Makefile
		    @$(CC) $(FLAGS) -c $< -o $@

bonus:      lib $(OBJ_B)
			@$(CC) $(FLAGS) $(OBJ_B) -Llibft -lft -Lmlx -lmlx -framework OpenGl -framework AppKit -o $(NAME)

clean:
	        @$(RM) $(OBJ_M)
			@$(RM) $(OBJ_B)
	        $(MAKE) -C libft clean
			$(MAKE) -C mlx clean

fclean:	    clean
		    @$(RM) $(NAME)

re:         fclean all

lib:
	        $(MAKE) -C libft 
			$(MAKE) -C mlx

.PHONY: all execute clean fclean re lib