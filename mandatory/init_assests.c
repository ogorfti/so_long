/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:20 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/10 21:50:29 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_assests(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx,
			map->win, map->w.img, j * 50, i * 50);
	if (map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(map->mlx,
			map->win, map->p.img, j * 50, i * 50);
		map->ppos_x = i;
		map->ppos_y = j;
	}
	if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx,
			map->win, map->c.img, j * 50, i * 50);
	if (map->map[i][j] == 'E')
	{
		mlx_put_image_to_window(map->mlx,
			map->win, map->e.img, j * 50, i * 50);
		map->epos_x = i;
		map->epos_y = j;
	}	
}

void	assests_norm(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			help_assests(map, i, j);
			j++;
		}
		i++;
	}
}

void	put_floor(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->cpe.c = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'C')
				map->cpe.c++;
			mlx_put_image_to_window(map->mlx, map->win,
				map->b.img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	put_assests(t_map *map)
{
	map->mlx = mlx_init();
	map->w.img = mlx_xpm_file_to_image(map->mlx, "textures/w.xpm",
			&map->w.img_width, &map->w.img_height);
	map->p.img = mlx_xpm_file_to_image(map->mlx, "textures/p.xpm",
			&map->p.img_width, &map->p.img_height);
	map->b.img = mlx_xpm_file_to_image(map->mlx, "textures/b.xpm",
			&map->b.img_width, &map->b.img_height);
	map->c.img = mlx_xpm_file_to_image(map->mlx, "textures/c.xpm",
			&map->c.img_width, &map->c.img_height);
	map->e.img = mlx_xpm_file_to_image(map->mlx, "textures/e.xpm",
			&map->e.img_width, &map->e.img_height);
	map->win = mlx_new_window(map->mlx, map->columns * 50,
			map->rows * 50, "So Long");
	put_floor(map);
	assests_norm(map);
}
