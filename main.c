/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:30:02 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/30 19:07:31 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	display_map(char **map)
{
	int	i;

	i = 0;
	printf("\t     MAP\n");
	while (map[i])
	{
		printf("\t%s", map[i]);
		i++;
	}
}

int	check_name(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)))
		return (0);
	return (1);
}

void	allocate_map(char *av, t_map *map)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		i;

	i = 0;
	fd1 = open(av, O_RDONLY);
	fd2 = open(av, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
		exit (0);
	line = get_next_line(fd1);
	map->columns = ft_strlen(line) - 1;
	map->rows = 1;
	while (get_next_line(fd1))
		map->rows++;
	map->map = malloc(sizeof(char *) * map->rows + 1);
	while (i < map->rows)
	{
		map->map[i] = get_next_line(fd2);
		i++;
	}
	map->map[i - 1] = ft_strjoin(map->map[i - 1], "\n");
	map->map[i] = 0;
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

void	cpe_error(t_cpe *cpe, int x)
{
	if (cpe->c < 1 || cpe->e != 1 || cpe->p != 1 || x == -1)
	{
		printf ("Invalid CPE!\n");
		exit (1);
	}
}

void	check_cpe(t_map *map, t_cpe *cpe)
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
			if (map->map[i][j] != 'C' && map->map[i][j] != 'P'
				&& map->map[i][j] != 'E' && map->map[i][j] != '0'
				&& map->map[i][j] != '1' && map->map[i][j] != '\n')
				cpe_error(cpe, -1);
			if (map->map[i][j] == 'C')
				cpe->c++;
			if (map->map[i][j] == 'P')
				cpe->p++;
			if (map->map[i][j] == 'E')
				cpe->e++;
			j++;
		}
		i++;
	}
	cpe_error(cpe, 0);
}

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

	i = 0;
	path = malloc (sizeof(char *) * map->rows + 1);
	while (map->map[i])
	{
		path[i] = map->map[i];
		i++;
	}
	path[i] = 0;
	path_norm(path, map);
	path_error(path, map->rows, map->columns);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_cpe	cpe;

	if (ac == 2)
	{
		if (check_name(av[1]))
		{
			ft_printf("Invalid map name!\n");
			exit (1);
		}
		else
		{
			allocate_map(av[1], &map);
			check_length(&map);
			check_walls(&map);
			check_cpe(&map, &cpe);
			check_path(&map);
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	ft_printf("Valid Map\n");
	return (0);
}
