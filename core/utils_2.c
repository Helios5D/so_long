/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:23:22 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 10:43:12 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	line;

	if (!map)
		return ;
	line = 0;
	while (map[line])
	{
		free(map[line]);
		line++;
	}
	free(map);
	map = NULL;
}

t_map	*copy_map(t_map map)
{
	t_map	*new_map;
	int		line;

	line = 0;
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->collectibles = map.collectibles;
	new_map->start_pos = map.start_pos;
	new_map->height = map.height;
	new_map->width = map.width;
	new_map->grid = malloc((map.height + 1) * sizeof(char *));
	if (!new_map->grid)
		return (NULL);
	while (map.grid[line])
	{
		new_map->grid[line] = ft_strdup(map.grid[line]);
		if (!new_map->grid[line])
			return (NULL);
		line++;
	}
	new_map->grid[line] = NULL;
	return (new_map);
}

int	itoa_get_num_len(long nb)
{
	int	total;

	total = 1;
	if (nb < 0)
	{
		nb = -nb;
		total++;
	}
	while (nb > 9)
	{
		nb /= 10;
		total++;
	}
	return (total);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	int		i;
	char	*str;

	sign = 0;
	size = itoa_get_num_len(n);
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	i = 0;
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	while (size - i > sign)
	{
		str[size - 1 - i++] = n % 10 + '0';
		n /= 10;
	}
	str[size] = '\0';
	return (str);
}

void	print_end(void)
{
	ft_printf("\x1B[0;36m\n__      ___      _                   \n");
	ft_printf("\\ \\    / (_)    | |\n");
	ft_printf(" \\ \\  / / _  ___| |_ ___  _ __ _   _\n");
	ft_printf("  \\ \\/ / | |/ __| __/ _ \\| '__| | | |\n");
	ft_printf("   \\  /  | | (__| || (_) | |  | |_| |\n");
	ft_printf("    \\/   |_|\\___|\\__\\___/|_|   \\__, |\n");
	ft_printf("                                __/ |\n");
	ft_printf("                               |___/\x1B[1;37m\n");
}
