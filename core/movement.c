/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:25:24 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 10:24:12 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_player(t_data *data)
{
	t_player	*player;
	t_position	*position;

	player = malloc(sizeof(t_player));
	if (!player)
		return (0);
	position = malloc(sizeof(t_position));
	if (!position)
		return (free(player), 0);
	position->x = data->map->start_pos->x;
	position->y = data->map->start_pos->y;
	player->position = position;
	player->collectibles = 0;
	data->player = player;
	return (1);
}

void	check_move(t_data *data)
{
	if (data->map->grid[data->player->position->y]
		[data->player->position->x] == 'C')
	{
		data->player->collectibles += 1;
		data->map->grid[data->player->position->y]
		[data->player->position->x] = '0';
	}
	else if (data->map->grid[data->player->position->y]
		[data->player->position->x] == 'E')
	{
		if (data->player->collectibles == data->map->collectibles)
		{
			print_end();
			destroy(data);
		}
	}
}

int	move(t_data *data, t_position direction)
{
	if (data->map->grid[data->player->position->y + direction.y]
		[data->player->position->x + direction.x] != '1')
	{
		data->player->position->x += direction.x;
		data->player->position->y += direction.y;
		check_move(data);
		update_panels(data);
		return (1);
	}
	return (0);
}

int	keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		destroy(data);
	if (key == XK_d)
		if (move(data, position(1, 0)))
			render_move(data, position(1, 0));
	if (key == XK_a)
		if (move(data, position(-1, 0)))
			render_move(data, position(-1, 0));
	if (key == XK_s)
		if (move(data, position(0, 1)))
			render_move(data, position(0, 1));
	if (key == XK_w)
		if (move(data, position(0, -1)))
			render_move(data, position(0, -1));
	return (0);
}
