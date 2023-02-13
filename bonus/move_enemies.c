/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:51:55 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 15:29:12 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_door(t_map *map, int i)
{
	if (map->cpex.c > 0)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b.img,
			map->enemies[i].y * 50, map->enemies[i].x * 50);
		mlx_put_image_to_window(map->mlx, map->win, map->e.img,
			map->enemies[i].y * 50, map->enemies[i].x * 50);
		mlx_put_image_to_window(map->mlx, map->win, map->x.img,
			map->new_y * 50, map->new_x * 50);
	}
}

void	enemies_norm(t_map *map, int i)
{
	if (map->new_x > 0 && map->new_y > 0 && map->new_x < map->rows
		&& !check_move(map, map->new_x, map->new_y, i)
		&& map->new_y < map->columns)
	{
		if (map->map[map->new_x][map->new_y] != '1' &&
			map->map[map->new_x][map->new_y] != 'C' &&
			check_open_door(map) == 0)
		{
			if (map->map[map->enemies[i].x][map->enemies[i].y] == 'E')
				check_door(map, i);
			else
			{
				mlx_put_image_to_window(map->mlx, map->win, map->x.img,
					map->new_y * 50, map->new_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->b.img,
					map->enemies[i].y * 50, map->enemies[i].x * 50);
			}
			map->enemies[i].x = map->new_x;
			map->enemies[i].y = map->new_y;
		}
	}
}

int	move_enemies(t_map *map)
{
	static int	i;
	int			dir;

	i = 0;
	while (i < map->nbrx)
	{
		dir = rand() % 4;
		map->new_x = map->enemies[i].x;
		map->new_y = map->enemies[i].y;
		if (dir == 0)
			map->new_x--;
		if (dir == 1)
			map->new_x++;
		if (dir == 2)
			map->new_y--;
		if (dir == 3)
			map->new_y++;
		enemies_norm(map, i);
		i++;
	}
	if (i == map->nbrx)
		i = 0;
	return (0);
}

void	kee_looping(t_map *map, int *keep)
{
	if (check_lose(map))
	{
		ft_printf("Game Over!\n");
		free_all (map, 0, 0);
	}
	if (map->cpex.c != 0 && *keep % 25 == 0)
		move_enemies(map);
	if (map->cpex.c == 0 && *keep % 3000 == 0)
		move_enemies(map);
	if (map->cpex.c >= 1 && *keep == 100)
		*keep = 0;
	if (map->cpex.c == 0 && *keep == 3000)
		*keep = 0;
	(*keep)++;
}

int	handle_animation(t_map *map)
{
	static int	keep;
	int			i;
	int			j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win,
					map->b.img, j * 50, i * 50);
				mlx_put_image_to_window(map->mlx, map->win,
					map->anim.img[(keep / 6) % 6], j * 50, i * 50);
			}
			j++;
		}
		i++;
	}
	kee_looping(map, &keep);
	return (0);
}
