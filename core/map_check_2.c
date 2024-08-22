/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:43:10 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 10:25:30 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_tile(t_map *map, int *map_items, int line, int col)
{
	if (map->grid[line][col] == 'C')
		map_items[2]++ ;
	else if (map->grid[line][col] == 'E')
		map_items[1]++ ;
	else if (map->grid[line][col] == 'P')
	{
		map->start_pos->x = col;
		map->start_pos->y = line;
		map_items[0]++ ;
	}
	else if (map->grid[line][col] != '0'
		&& map->grid[line][col] != '1')
		return (0);
	return (1);
}
//ft_error(UNKNOWN_CHAR_ERR)

int	map_items(t_map *map)
{
	int	line;
	int	col;
	int	*map_items;

	map_items = malloc(3 * sizeof(int));
	if (map_items == NULL)
		return (0);
	map_items[0] = 0;
	map_items[1] = 0;
	map_items[2] = 0;
	line = 0;
	col = 0;
	while (map->grid[line++])
	{
		col = 0;
		while (map->grid[line - 1][col++])
		{
			if (map_tile(map, map_items, line - 1, col - 1) == 0)
				return (free(map_items), ft_error(UNKNOWN_CHAR_ERR), 0);
		}
	}
	if (map_items[0] == 1 && map_items[1] == 1 && map_items[2] >= 1)
		return (map->collectibles = map_items[2], free(map_items), 1);
	return (free(map_items), ft_error(ITEM_ERR), 0);
}

int	is_map_valid(t_map *map)
{
	if (!map)
		return (0);
	map->start_pos = malloc(sizeof(t_position));
	if (!map->start_pos)
		return (0);
	map->start_pos->x = 0;
	map->start_pos->y = 0;
	map->collectibles = 0;
	if (!(are_dimensions_valid(map) && is_map_closed(map->grid)
			&& map_items(map) && is_map_playable(map)))
		return (0);
	return (1);
}
