/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:52:11 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 16:40:34 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_name(t_map *map)
{
	char	*joiner;
	char	*line;
	int		fd;

	joiner = ft_calloc1(1, 1);
	fd = open ("textures/coins.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("There's a problem with FD!\n");
		free_all(map, -1, 1);
	}
	while (1)
	{
			line = get_next_line(fd);
		if (!line)
			break ;
		joiner = ft_strjoin1(joiner, line);
		free(line);
	}
	map->coins = ft_split(joiner, '\n');
	free (joiner);
}

void	init_coins(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		map->anim.img[i] = mlx_xpm_file_to_image(map->mlx, map->coins[i],
				&map->anim.img_width, &map->anim.img_height);
		if (!map->anim.img[i])
		{
			ft_printf("Invalid XPM file! : %s\n", map->coins[i]);
			exit (1);
		}
		i++;
	}
}

void	position_of_enemies(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->idx.k = 0;
	map->enemies = malloc(map->nbrx * sizeof(t_enemy));
	if (!map->enemies)
	{
		free_coins (map);
		free_all(map, -1, 1);
	}
	while (++i < map->rows)
	{	
		j = -1;
		while (++j < map->columns)
		{
			if (map->map[i][j] == 'X')
			{
				map->enemies[map->idx.k].x = i;
				map->enemies[map->idx.k].y = j;
				map->idx.k++;
			}
		}
	}
}

int	check_move(t_map *map, int new_x, int new_y, int a)
{
	int	i;

	i = 0;
	while (i < map->nbrx)
	{
		if (i != a)
		{
			if (map->enemies[i].x == new_x && map->enemies[i].y == new_y)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_lose(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nbrx)
	{
		if (map->enemies[i].x == map->ppos_x
			&& map->enemies[i].y == map->ppos_y)
			return (1);
		i++;
	}
	return (0);
}
