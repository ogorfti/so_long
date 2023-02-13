/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:57:09 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 16:14:51 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}

void	free_coins(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(map->mlx, map->anim.img[i]);
		i++;
	}
}

void	free_2d(t_map *map, int x)
{
	mlx_destroy_image(map->mlx, map->w.img);
	mlx_destroy_image(map->mlx, map->b.img);
	mlx_destroy_image(map->mlx, map->e.img);
	mlx_destroy_image(map->mlx, map->p.img);
	mlx_destroy_image(map->mlx, map->x.img);
	if (x == 0)
	{
		free_coins (map);
		mlx_destroy_image(map->mlx, map->p_a.img);
		mlx_destroy_image(map->mlx, map->p_d.img);
		mlx_destroy_image(map->mlx, map->p_w.img);
		free (map->enemies);
	}
	mlx_destroy_window(map->mlx, map->win);
}

void	free_all(t_map *map, int x, int e)
{
	free_2d (map, x);
	free (map->map);
	exit (e);
}
