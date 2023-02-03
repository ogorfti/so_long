/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:01:35 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/03 20:15:45 by ogorfti          ###   ########.fr       */
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
			printf ("Invalid length!\n");
			exit (1);
		}
		i++;
	}
}

void	cpe_error(t_cpe *cpe, int x)
{
	if (cpe->c < 1 || cpe->e != 1 || cpe->p != 1 || x == -1)
	{
		printf ("Invalid CPE!\n");
		exit (1);
	}
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
			if (map->map[i][j] != 'C' && map->map[i][j] != 'P'
				&& map->map[i][j] != 'E' && map->map[i][j] != '0'
				&& map->map[i][j] != '1' && map->map[i][j] != '\n')
				cpe_error(&map->cpe, -1);
			if (map->map[i][j] == 'C')
				map->cpe.c++;
			if (map->map[i][j] == 'P')
				map->cpe.p++;
			if (map->map[i][j] == 'E')
				map->cpe.e++;
			j++;
		}
		i++;
	}
	cpe_error(&map->cpe, 0);
}

void	wall_error(void)
{
	printf ("Invalid Wall!\n");
	exit (1);
}

void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\n')
	{
		if (map->map[0][i] != '1')
			wall_error();
		if (map->map[map->rows - 1][i] != '1')
			wall_error();
		if (i < 5)
		{
			if (map->map[i][0] != '1')
				wall_error();
			if (map->map[i][map->columns - 1] != '1')
				wall_error();
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	//t_cpe	cpe;

	check_walls(map);
	check_length(map);
	check_cpe(map);
}
