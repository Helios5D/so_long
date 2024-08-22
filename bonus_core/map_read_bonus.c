/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:45:18 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 10:46:43 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_ber(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (i > 4 && path[i - 1] == 'r' && path[i - 2] == 'e'
		&& path[i - 3] == 'b' && path[i - 4] == '.')
		return (1);
	return (0);
}

int	count_lines(char *path)
{
	char	*line;
	int		lines;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || !is_ber(path))
		return (ft_error(PATH_ERR), 0);
	lines = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_error(EMPTY_ERR), 0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		lines ++;
	}
	return (close(fd), lines);
}

char	**fill_map(char **map, int fd, int len)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line)
	{
		map[i] = line;
		remove_nl(map[i]);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	while (map[j])
		j++;
	if (j == len)
		return (map);
	return (NULL);
}

t_map	*create_map(char *path)
{
	t_map	*map;
	int		fd;
	int		lines;

	lines = count_lines(path);
	if (lines == 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	if ((fd < 0) || !is_ber(path))
		return (close(fd), ft_error(PATH_ERR), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = malloc ((lines + 1) * sizeof(char *));
	if (!map->grid)
		return (free(map), close(fd), NULL);
	map->grid = fill_map(map->grid, fd, lines);
	return (close(fd), map);
}
