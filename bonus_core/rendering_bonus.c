/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:24:35 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 11:15:35 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	create_images(t_data *data)
{
	t_images	*imgs;
	int			height;
	int			width;

	imgs = malloc(sizeof(t_images));
	if (!imgs)
		return (0);
	imgs->carrot = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/carrot.xpm", &width, &height);
	imgs->rabbit = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/rabbit.xpm", &width, &height);
	imgs->grass = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/grass.xpm", &width, &height);
	imgs->tree = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/tree.xpm", &width, &height);
	imgs->hole = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/hole.xpm", &width, &height);
	imgs->evil_rabbit = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/evil_rabbit.xpm", &width, &height);
	imgs->panel = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/panel.xpm", &width, &height);
		imgs->panel_2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/panel_2.xpm", &width, &height);
	return (data->images = imgs, 1);
}

void	put_tile(t_data *data, int line, int col)
{
	if (data->map->grid[line][col] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->tree, col * IMG_SIZE, line * IMG_SIZE);
	else if (data->map->grid[line][col] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->grass, col * IMG_SIZE, line * IMG_SIZE);
	else if (data->map->grid[line][col] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->rabbit, col * IMG_SIZE, line * IMG_SIZE);
	else if (data->map->grid[line][col] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->carrot, col * IMG_SIZE, line * IMG_SIZE);
	else if (data->map->grid[line][col] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->hole, col * IMG_SIZE, line * IMG_SIZE);
	else if (data->map->grid[line][col] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->evil_rabbit, col * IMG_SIZE, line * IMG_SIZE);
}

void	render_map(t_data *data)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (data->map->grid[line])
	{
		col = 0;
		while (data->map->grid[line][col])
		{
			put_tile(data, line, col);
			col++;
		}
		line++;
	}
}

void	render_move(t_data *data, t_position position)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->images->rabbit, data->player->position->x * IMG_SIZE,
		data->player->position->y * IMG_SIZE);
	if (data->map->grid[data->player->position->y - position.y]
		[data->player->position->x - position.x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->hole,
			(data->player->position->x - position.x) * IMG_SIZE,
			(data->player->position->y - position.y) * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->grass,
			(data->player->position->x - position.x) * IMG_SIZE,
			(data->player->position->y - position.y) * IMG_SIZE);
}

void	update_panels(t_data *data)
{
	static int	moves = -1;
	char		*str_moves;
	char		*str_collected;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->images->panel, 3, 6);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->images->panel_2, 103, 6);
	moves++;
	str_moves = ft_itoa(moves);
	str_collected = ft_itoa(data->player->collectibles);
	if (!str_collected)
	{
		data->status = 1;
		destroy(data);
	}
	mlx_string_put(data->mlx_ptr,
		data->win_ptr, 34, 26, 16777215, str_moves);
	mlx_string_put(data->mlx_ptr,
		data->win_ptr, 125, 26, 16777215, str_collected);
	free(str_collected);
	free(str_moves);
}
