/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:41:07 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/12 22:53:03 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_map(char **map)
{
	int	i;

	i = 0;
	ft_printf("\tMAP\n");
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

void	display_pox(t_map *map)
{
	int i;

	i = 0;
	while (i < map->nbrx)
	{
		ft_printf("enemy%d : x = %d\ty = %d\n", i, map->enemies[i].x, map->enemies[i].y);
		i++;
	}
}

int	check_name(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)))
		return (0);
	return (1);
}

void	get_name(t_map *map)
{
	char	*joiner;
	char	*line;
	int		fd;

	joiner = ft_calloc1(1, 1);
	fd = open ("coins.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("There's a problem with FD!\n");
		exit (1);
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
	int i;

	i = 0;
	// int k=0;
	// while (map->coins[k])
	// {
	// 	ft_printf("%s\n", map->coins[k]);
	// 	k++;
	// }
	while (i < 6)
	{
		map->anim.img[i] = mlx_xpm_file_to_image(map->mlx, map->coins[i],
			&map->anim.img_width, &map->anim.img_height);
		if (!map->anim.img[i])
		{
			ft_printf("There's a problem with the XPM file: %s\n", map->coins[i]);
			exit (1);
		}
		i++;
	}
}

void	position_of_enemies(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	map->enemies = malloc(map->nbrx * sizeof(t_enemy));
	while (i < map->rows)
	{	
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'X')
			{
				map->enemies[k].x = i;
				map->enemies[k].y = j;
				k++;
			}
			j++;
		}
		i++;
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
		if (map->enemies[i].x == map->ppos_x && map->enemies[i].y == map->ppos_y)
				return (1);	
		i++;
	}
	return (0);
}

int	move_enemies(t_map *map)
{
	int	new_x;
	int	new_y;
	int dir;
	static int	i;

	i = 0;
	while (i < map->nbrx)
	{
		dir = rand() % 4;
		new_x = map->enemies[i].x;
		new_y = map->enemies[i].y;
		if (dir == 0)
			new_x--;
		if (dir == 1)
			new_x++;
		if (dir == 2)
			new_y--;
		if (dir == 3)
			new_y++;
		if (new_x > 0 && new_y > 0 && new_x < map->rows && new_y < map->columns && check_move(map, new_x, new_y, i) == 0)
		{
			if (map->map[new_x][new_y] != '1' && map->map[new_x][new_y] != 'C')
				{
					// ft_printf("xx : %d \t xy : %d\n", new_x, new_y);
					// ft_printf("px : %d \t py : %d\n", map->ppos_x, map->ppos_y);
					mlx_put_image_to_window(map->mlx, map->win, map->x.img, new_y * 50, new_x * 50);
					mlx_put_image_to_window(map->mlx, map->win, map->b.img, map->enemies[i].y * 50, map->enemies[i].x * 50);
					map->enemies[i].x = new_x;
					map->enemies[i].y = new_y;
				}
		}
		i++;
	}
	if (i == map->nbrx)
		i = 0;
	return (0);
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
	if (check_lose(map))
	{
		//mlx_put_image_to_window(map->mlx, map->win, map->b.img, map->ppos_y * 50, map->ppos_y * 50);
		ft_printf("Game Over!\n");
		exit (1);
	}
	if (map->cpex.c != 0 && keep % 25 == 0)
		move_enemies(map);
	if (map->cpex.c == 0 && keep % 3000 == 0)
		move_enemies(map);
	// ft_printf("keep : %d\n", keep);
	if (map->cpex.c >= 1 && keep == 100)
		keep = 0;
	if (map->cpex.c == 0 && keep == 3000)
		keep = 0;
	keep++;
	return (0);
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
			get_name(&map);
			init_coins(&map);
			position_of_enemies(&map);
			// ft_printf("nbrx : %d\n", map.nbrx);
			// display_pox(&map);
			mlx_loop_hook(map.mlx, handle_animation, &map);
			handle_keys(&map);
			mlx_loop(map.mlx);
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	return (0);
}
