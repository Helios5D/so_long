/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:06:58 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 13:37:33 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// INCLUDES

# include "/home/hdaher/sgoinfre/hdaher/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// MACROS

# define IMG_SIZE 64
# define BUFFER_SIZE 1024
# define F "-schumacher-clean-bold-r-normal--10-100-75-75-c-90-iso646.1991-irv"

# define ARG_ERR "Error\nWrong number of arguments.\n"
# define PATH_ERR "Error\nThe map path isn't valid.\n"
# define EMPTY_ERR "Error\nThe map file is empty.\n"
# define MAP_SIZE_ERR "Error\nThe map must be a rectangle.\n"
# define MAP_CLOSED_ERR "Error\nThe map must be closed.\n"
# define UNKNOWN_CHAR_ERR "Error\nUnknown character found when parsing map.\n"
# define IMPOSSIBLE_MAP_ERR "Error\nThere is no valid path in the map.\n"
# define ITEM_ERR "Error\nMap must have 1 exit, 1 spawn and at least 1 item.\n"

// STRUCTURES

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_player
{
	t_position	*position;
	int			collectibles;
}	t_player;

typedef struct s_images
{
	void	*rabbit;
	void	*carrot;
	void	*grass;
	void	*hole;
	void	*tree;
	void	*evil_rabbit;
	void	*panel;
	void	*panel_2;
}	t_images;

typedef struct s_map
{
	char		**grid;
	int			collectibles;
	int			height;
	int			width;
	t_position	*start_pos;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			status;

	t_player	*player;
	t_images	*images;
	t_map		*map;
}	t_data;

// Prototypes

// exit.c
void		free_all_images(t_data *data);
void		free_t_map(t_map *map);
void		free_t_player(t_player *player);
void		free_main(t_data *data, int level);

// map_check_2.c
int			map_tile(t_map *map, int *map_items, int line, int col);
int			map_items(t_map *map);
int			is_map_valid(t_map *map);

// map_check.c
int			are_dimensions_valid(t_map *map);
int			is_map_closed(char **map);
void		flood_fill_map(t_map *map, int line, int col);
int			is_map_playable(t_map *map);

// map_read.c

int			is_ber(char *path);
int			count_lines(char *path);
char		**fill_map(char **map, int fd, int len);
t_map		*create_map(char *path);

// movement.c
int			create_player(t_data *data);
void		check_move(t_data *data);
int			move(t_data *data, t_position direction);
int			keypress(int key, t_data *data);

// rendering.c
int			create_images(t_data *data);
void		put_tile(t_data *data, int line, int col);
void		render_map(t_data *data);
void		render_move(t_data *data, t_position position);
void		update_panels(t_data *data);

// so_long.c
int			destroy(t_data *data);
void		free_all_images(t_data *data);
t_map		*create_and_check_map(t_data *data, char *path);

// utils_1.c
int			ft_strlen(char *str);
char		*ft_strdup(const char *s);
t_position	position(int x, int y);
void		remove_nl(char *str);
void		*ft_error(char *str);

// utils_2.c
void		free_map(char **map);
t_map		*copy_map(t_map map);
char		*ft_itoa(int n);
int			itoa_get_num_len(long nb);
void		print_end(int win);

// get_next_line.c
char		*get_next_line(int fd);
char		*select_line(char **str);

// get_next_line_utils.c
void		ft_strdel(char **str);
int			ft_strlen(char *str);
char		*conc_strings(char *str, char *buffer);
int			is_new_line(char *str);
char		*delete_first_chars(char *str, int a);

#endif
