/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:24:29 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/01 23:26:43 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_path(char **path, int i, int j, int checker)
{
	if (path[i][j + 1] != '1' && path[i][j + 1] != 'P')
	{
		path[i][j + 1] = 'P';
		checker = 1;
	}
	if (path[i][j - 1] != '1' && path[i][j - 1] != 'P')
	{
		path[i][j - 1] = 'P';
		checker = 1;
	}
	if (path[i - 1][j] != '1' && path[i - 1][j] != 'P')
	{
		path[i - 1][j] = 'P';
		checker = 1;
	}
	if (path[i + 1][j] != '1' && path[i + 1][j] != 'P')
	{
		path[i + 1][j] = 'P';
		checker = 1;
	}
	return (checker);
}

void	path_error(char **path, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (path[i][j] == 'C' || path[i][j] == 'E')
			{
				printf ("Invalid path!\n");
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
	int		i;
	int		j;

	i = 0;
	path = malloc (sizeof(char *) * map->rows + 1);
	while (map->map[i])
	{
		j = 0;
		path[i] = malloc(sizeof(char) * map->columns + 1);
		while (map->map[i][j])
		{
			path[i][j] = map->map[i][j];
			j++;
		}
		path[i][j] = '\0';
		i++;
	}
	path[i] = 0;
	path_norm(path, map);
	path_error(path, map->rows, map->columns);
}
