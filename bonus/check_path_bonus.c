/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:26:39 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 16:29:39 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	fill_path(char **path, int i, int j, int checker)
{
	if (path[i][j + 1] != '1' && path[i][j + 1] != 'P' && path[i][j + 1] != 'X')
	{
		path[i][j + 1] = 'P';
		checker = 1;
	}
	if (path[i][j - 1] != '1' && path[i][j - 1] != 'P' && path[i][j - 1] != 'X')
	{
		path[i][j - 1] = 'P';
		checker = 1;
	}
	if (path[i - 1][j] != '1' && path[i - 1][j] != 'P' && path[i - 1][j] != 'X')
	{
		path[i - 1][j] = 'P';
		checker = 1;
	}
	if (path[i + 1][j] != '1' && path[i + 1][j] != 'P' && path[i + 1][j] != 'X')
	{
		path[i + 1][j] = 'P';
		checker = 1;
	}
	return (checker);
}

void	path_error(char **path, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (path[i][j] == 'C' || path[i][j] == 'E')
			{
				ft_printf ("Invalid path!\n");
				free (map->map);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	path_norm(char **path, t_map *map)
{
	int	checker;
	int	i;
	int	j;

	j = 0;
	i = 0;
	checker = 1;
	while (checker == 1)
	{
		i = 0;
		checker = 0;
		while (i < map->rows)
		{
			j = 0;
			while (j < map->columns)
			{
				if (path[i][j] == 'P')
					checker = fill_path(path, i, j, checker);
				j++;
			}
			i++;
		}
	}
}

void	check_path(t_map *map)
{
	char	**path;

	map->idx.i = 0;
	path = malloc (sizeof(char *) * map->rows + 1);
	if (!path)
	{
		free_map (map->map);
		exit (1);
	}
	while (map->map[map->idx.i])
	{
		map->idx.j = 0;
		path[map->idx.i] = malloc(sizeof(char) * map->columns + 1);
		while (map->map[map->idx.i][map->idx.j])
		{
			path[map->idx.i][map->idx.j] = map->map[map->idx.i][map->idx.j];
			map->idx.j++;
		}
		path[map->idx.i][map->idx.j] = '\0';
		map->idx.i++;
	}
	path[map->idx.i] = 0;
	path_norm(path, map);
	path_error(path, map);
	free_map(path);
}
