/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:30:02 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/01 23:37:56 by ogorfti          ###   ########.fr       */
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
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx,
					map->win, map->w.img, j * 50, i * 50);
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx,
					map->win, map->p.img, j * 50, i * 50);
			if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx,
					map->win, map->b.img, j * 50, i * 50);
			if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx,
					map->win, map->c.img, j * 50, i * 50);
			if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx,
					map->win, map->e.img, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	put_assests(t_map *map)
{
	map->mlx = mlx_init();
	map->w.img = mlx_xpm_file_to_image(map->mlx, "sprites/w.xpm",
			&map->w.img_width, &map->w.img_height);
	map->p.img = mlx_xpm_file_to_image(map->mlx, "sprites/p.xpm",
			&map->p.img_width, &map->p.img_height);
	map->b.img = mlx_xpm_file_to_image(map->mlx, "sprites/b.xpm",
			&map->b.img_width, &map->b.img_height);
	map->c.img = mlx_xpm_file_to_image(map->mlx, "sprites/c.xpm",
			&map->c.img_width, &map->c.img_height);
	map->e.img = mlx_xpm_file_to_image(map->mlx, "sprites/e.xpm",
			&map->e.img_width, &map->e.img_height);
	map->win = mlx_new_window(map->mlx, map->columns * 50,
			map->rows * 50, "So Long");
	assests_norm(map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

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
			check_map(&map);
			check_path(&map);
			put_assests(&map);
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	return (0);
}
