/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:50:18 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/10 18:24:55 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_length(t_map *map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map->map[i]);
	while (i < map->rows)
	{
		if (len != ft_strlen(map->map[i]))
		{
			ft_printf ("Invalid length!\n");
			exit (1);
		}
		i++;
	}
}

void	cpex_error(t_map *map, int x)
{
	if (map->cpex.c < 1 || map->cpex.e != 1 || map->cpex.p != 1 || x == -1)
	{
		ft_printf ("Invalid CPEX!\n");
		free_map(map->map);
		exit (1);
	}
}

void	cpex_norm(t_map *map, int i, int j)
{
	if (map->map[i][j] != 'C' && map->map[i][j] != 'P'
		&& map->map[i][j] != 'E' && map->map[i][j] != '0'
		&& map->map[i][j] != '1' && map->map[i][j] != '\n'
		&& map->map[i][j] != 'X')
		cpex_error(map, -1);
	if (map->map[i][j] == 'C')
		map->cpex.c++;
	if (map->map[i][j] == 'P')
		map->cpex.p++;
	if (map->map[i][j] == 'E')
		map->cpex.e++;
}

void	check_cpex(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->cpex.c = 0;
	map->cpex.p = 0;
	map->cpex.e = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			cpex_norm(map, i, j);
			j++;
		}
		i++;
	}
	cpex_error(map, 0);
}

void	check_map(t_map *map)
{
	check_walls(map);
	check_length(map);
	check_cpex(map);
}
