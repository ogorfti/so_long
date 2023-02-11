/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:01:35 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/10 16:43:51 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	cpe_error(t_map *map, int x)
{
	if (map->cpe.c < 1 || map->cpe.e != 1 || map->cpe.p != 1 || x == -1)
	{
		ft_printf ("Invalid CPE!\n");
		free_map(map->map);
		exit (1);
	}
}

void	cpe_norm(t_map *map, int i, int j)
{
	if (map->map[i][j] != 'C' && map->map[i][j] != 'P'
		&& map->map[i][j] != 'E' && map->map[i][j] != '0'
		&& map->map[i][j] != '1' && map->map[i][j] != '\n')
		cpe_error(map, -1);
	if (map->map[i][j] == 'C')
		map->cpe.c++;
	if (map->map[i][j] == 'P')
		map->cpe.p++;
	if (map->map[i][j] == 'E')
		map->cpe.e++;
}

void	check_cpe(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->cpe.c = 0;
	map->cpe.p = 0;
	map->cpe.e = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			cpe_norm(map, i, j);
			j++;
		}
		i++;
	}
	cpe_error(map, 0);
}

void	check_map(t_map *map)
{
	check_walls(map);
	check_length(map);
	check_cpe(map);
}
