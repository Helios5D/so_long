/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:10:47 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/05 11:48:48 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_images(t_data *data)
{
	if (data->images->rabbit)
		mlx_destroy_image(data->mlx_ptr, data->images->rabbit);
	if (data->images->hole)
		mlx_destroy_image(data->mlx_ptr, data->images->hole);
	if (data->images->carrot)
		mlx_destroy_image(data->mlx_ptr, data->images->carrot);
	if (data->images->grass)
		mlx_destroy_image(data->mlx_ptr, data->images->grass);
	if (data->images->tree)
		mlx_destroy_image(data->mlx_ptr, data->images->tree);
	if (data->images->panel_2)
		mlx_destroy_image(data->mlx_ptr, data->images->panel_2);
	free(data->images);
}

void	free_t_map(t_map *map)
{
	if (map)
	{
		if (map->start_pos)
			free(map->start_pos);
		if (map->grid)
			free_map(map->grid);
		free(map);
	}
}

void	free_t_player(t_player *player)
{
	if (player->position)
		free(player->position);
	free(player);
}

void	free_main(t_data *data, int level)
{
	if (level == 0)
		free_t_map(data->map);
	else if (level == 1)
	{
		free_t_map(data->map);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	else if (level == 2)
	{
		free_t_player(data->player);
		free_all_images(data);
		free_t_map(data->map);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
