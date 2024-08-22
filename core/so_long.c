/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:58:17 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/02 14:02:46 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_data *data)
{
	int	exit_val;

	exit_val = data->status;
	free_t_player(data->player);
	free_t_map(data->map);
	free_all_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(exit_val);
}

t_map	*create_and_check_map(t_data *data, char *path)
{
	t_map		*map;

	map = create_map(path);
	if (!map || !map->grid)
		return (NULL);
	if (!is_map_valid(map))
		return (free_t_map(map), NULL);
	data->map = map;
	data->status = 0;
	return (map);
}

int	check_images(t_data *data)
{
	if (!data->images->carrot || !data->images->grass
		|| !data->images->hole || !data->images->panel_2
		|| !data->images->rabbit || !data->images->tree)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_data		data;

	if (ac != 2)
		return (ft_error(ARG_ERR), 1);
	map = create_and_check_map(&data, av[1]);
	if (map == NULL)
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (free_main(&data, 0), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, map->width * IMG_SIZE,
			map->height * IMG_SIZE, "window");
	if (!data.win_ptr)
		return (free_main(&data, 1), 1);
	if (!(create_player(&data) && create_images(&data)))
		return (free_main(&data, 1), 1);
	if (!check_images(&data))
		return (free_main(&data, 2), 1);
	mlx_set_font(data.mlx_ptr, data.win_ptr, F);
	render_map(&data);
	update_panels(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &data);
	mlx_loop(data.mlx_ptr);
}
