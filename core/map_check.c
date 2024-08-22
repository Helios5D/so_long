/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:33:43 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 10:24:48 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	are_dimensions_valid(t_map *map)
{
	int	line;
	int	line_len;

	line = 0;
	line_len = ft_strlen(map->grid[0]);
	while (map->grid[line])
	{
		if (ft_strlen(map->grid[line]) != line_len)
			return (ft_error(MAP_SIZE_ERR), 0);
		line++;
	}
	map->height = line;
	map->width = line_len;
	return (1);
}

int	is_map_closed(char **map)
{
	int	line;
	int	col;
	int	line_len;
	int	col_len;

	line = 0;
	col = 0;
	col_len = 0;
	line_len = ft_strlen(map[0]);
	while (map[col_len])
		col_len++;
	while (map[line])
	{
		if (map[line][0] != '1' || map[line][line_len - 1] != '1')
			return (ft_error(MAP_CLOSED_ERR), 0);
		line++;
	}
	while (map[0][col])
	{
		if (map[0][col] != '1' || map[col_len - 1][col] != '1')
			return (ft_error(MAP_CLOSED_ERR), 0);
		col++;
	}
	return (1);
}

void	flood_fill_map(t_map *map, int line, int col)
{
	if (line < 1 || line >= map->height - 1 || col < 1
		|| col >= map->width - 1 || map->grid[line][col] == '1')
		return ;
	if (map->grid[line][col] == '0' || map->grid[line][col] == 'C'
		|| map->grid[line][col] == 'E' || map->grid[line][col] == 'P')
		map->grid[line][col] = '1';
	flood_fill_map(map, line + 1, col);
	flood_fill_map(map, line - 1, col);
	flood_fill_map(map, line, col + 1);
	flood_fill_map(map, line, col - 1);
}

int	is_map_playable(t_map *map)
{
	int		line;
	int		col;
	t_map	*filled_map;

	filled_map = copy_map(*map);
	if (filled_map == NULL)
		return (0);
	flood_fill_map(filled_map, map->start_pos->y, map->start_pos->x);
	line = 0;
	col = 0;
	while (filled_map->grid[line])
	{
		col = 0;
		while (filled_map->grid[line][col])
		{
			if (filled_map->grid[line][col] != '0'
				&& filled_map->grid[line][col] != '1')
				return (free_map(filled_map->grid),
					free(filled_map), ft_error(IMPOSSIBLE_MAP_ERR), 0);
			col++;
		}
		line++;
	}
	return (free_map(filled_map->grid), free(filled_map), 1);
}
