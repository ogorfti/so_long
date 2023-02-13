/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:05:26 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 16:23:36 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_coins(t_map *map, int a, int b, void *pside)
{
	if (map->map[map->ppos_x - a][map->ppos_y - b] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b.img,
			map->ppos_y * 50, map->ppos_x * 50);
		mlx_put_image_to_window(map->mlx, map->win, map->b.img,
			(map->ppos_y - b) * 50, (map->ppos_x - a) * 50);
		mlx_put_image_to_window(map->mlx, map->win, pside,
			(map->ppos_y - b) * 50, (map->ppos_x - a) * 50);
		map->map[map->ppos_x - a][map->ppos_y - b] = '0';
		map->cpex.c--;
		map->check = 1;
	}
}

void	handle_move(t_map *map, int a, int b, void *pside)
{
	static int	nbr;

	winner_msg(map->map[map->ppos_x - a][map->ppos_y - b], map);
	if (map->map[map->ppos_x - a][map->ppos_y - b] != '1')
	{
		handle_coins(map, a, b, pside);
		if (map->map[map->ppos_x][map->ppos_y] == 'E')
		{
			mlx_put_image_to_window(map->mlx, map->win, pside,
				(map->ppos_y - b) * 50, (map->ppos_x - a) * 50);
			mlx_put_image_to_window(map->mlx, map->win, map->b.img,
				map->ppos_y * 50, map->ppos_x * 50);
			mlx_put_image_to_window(map->mlx, map->win, map->e.img,
				map->ppos_y * 50, map->ppos_x * 50);
		}
		else if (map->check != 1)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->b.img,
				map->ppos_y * 50, map->ppos_x * 50);
			mlx_put_image_to_window(map->mlx, map->win, pside,
				(map->ppos_y - b) * 50, (map->ppos_x - a) * 50);
		}
		write_pm(map, a, b, &nbr);
		fbi_open_up(map);
	}
}

int	key_callback(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	map->check = 0;
	if (key == 53)
		free_all(map, 0, 0);
	if (key == 126)
		handle_move(map, 1, 0, map->p_w.img);
	if (key == 125)
		handle_move(map, -1, 0, map->p.img);
	if (key == 124)
		handle_move(map, 0, -1, map->p_d.img);
	if (key == 123)
		handle_move(map, 0, 1, map->p_a.img);
	return (0);
}

void	handle_keys(t_map *map)
{
	init_xpm(map);
	mlx_string_put (map->mlx, map->win,
		(map->columns * 50) - 137, 15, 0x000000, "PM : 0");
	mlx_hook(map->win, 2, 0, key_callback, (void *)map);
	mlx_hook(map->win, 17, 0, close_window, (void *)map);
}
