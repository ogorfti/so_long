/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:30:02 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/04 18:57:10 by ogorfti          ###   ########.fr       */
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
	if (!line)
	{
		ft_printf("khawya\n");
		exit (1);
	}
	map->columns = ft_strlen(line) - 1;
	free (line);
		
	map->rows = 1;
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break;
		free (line);
		map->rows++;
	}
	while (get_next_line(fd1))
		map->rows++;
	map->map = malloc(sizeof(char *) * map->rows + 1);
	while (i < map->rows)
	{
		map->map[i] = get_next_line(fd2);
		//printf("%p\n", map->map[i]);
		i++;
	}

	map->map[i - 1] = ft_strjoin1(map->map[i - 1], "\n");
	map->map[i] = 0;
	// while (1);
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
			{
				mlx_put_image_to_window(map->mlx,
					map->win, map->p.img, j * 50, i * 50);
				map->ppos_x = i;
				map->ppos_y = j;
			}
			if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx,
					map->win, map->c.img, j * 50, i * 50);
			if (map->map[i][j] == 'E')
			{
				mlx_put_image_to_window(map->mlx,
					map->win, map->e.img, j * 50, i * 50);
				map->epos_x = i;
				map->epos_y = j;
			}
			j++;
		}
		i++;
	}
}

void put_floor(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->cpe.c = 0;
	//	map->cpe.c = 0 this line for problem in memory;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'C')
			{
				map->cpe.c++;
			}
			mlx_put_image_to_window(map->mlx, map->win, map->b.img, j * 50, i * 50);
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
	put_floor(map);
	assests_norm(map);
}

void	winner_msg(char c, int cpe)
{
	if (c == 'E' && cpe == 0)
	{
		ft_printf("Congrats you win!\n");
		exit(0);	
	}
}

int key_callback(int key, void *param)
{
	static int	nbr;
	int			check;
	t_map *map = (t_map *)param;

	check = 0;
	if (key == 53)
		exit(0);
	if (map->cpe.c == 0)
	{
		map->open.img = mlx_xpm_file_to_image(map->mlx, "sprites/open.xpm", &map->open.img_width,& map->open.img_height);
		mlx_put_image_to_window(map->mlx, map->win, map->open.img, map->epos_y * 50, map->epos_x * 50);
	}
	map->p_d.img =  mlx_xpm_file_to_image(map->mlx, "sprites/p_d.xpm", &map->p_d.img_width, &map->p_d.img_height);
	map->p_a.img =  mlx_xpm_file_to_image(map->mlx, "sprites/p_a.xpm", &map->p_a.img_width, &map->p_a.img_height);
	map->p_w.img =  mlx_xpm_file_to_image(map->mlx, "sprites/p_w.xpm", &map->p_w.img_width, &map->p_w.img_height);
	if (key == 126)
	{
		winner_msg(map->map[map->ppos_x - 1][map->ppos_y], map->cpe.c );
		if (map->map[map->ppos_x - 1][map->ppos_y] != '1')
		{
			if (map->map[map->ppos_x - 1][map->ppos_y] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, (map->ppos_x - 1) * 50);	
				mlx_put_image_to_window(map->mlx, map->win, map->p_w.img , map->ppos_y * 50, (map->ppos_x - 1) * 50);	
				map->map[map->ppos_x - 1][map->ppos_y] = '0';
				map->cpe.c--;
				check = 1;
			}
			if (map->map[map->ppos_x][map->ppos_y] == 'E')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->p_w.img , map->ppos_y * 50, (map->ppos_x - 1) * 50);	
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->e.img , map->ppos_y * 50, map->ppos_x * 50);
			}
			else if(check != 1)
			{
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->p_w.img , map->ppos_y * 50, (map->ppos_x - 1) * 50);
			}
			map->ppos_x = map->ppos_x - 1;
			check = 0;
			nbr++;
			ft_printf("PM : %d\n", nbr);
		}
	}
	if (key == 125)
	{
		winner_msg(map->map[map->ppos_x + 1][map->ppos_y], map->cpe.c);
		if (map->map[map->ppos_x + 1][map->ppos_y] != '1')
		{
			if (map->map[map->ppos_x + 1][map->ppos_y] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, (map->ppos_x + 1) * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->p.img , map->ppos_y * 50, (map->ppos_x + 1) * 50);	
				map->map[map->ppos_x + 1][map->ppos_y] = '0';
				map->cpe.c--;
				check = 1;
			}
			if (map->map[map->ppos_x][map->ppos_y] == 'E')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->p.img , map->ppos_y * 50, (map->ppos_x + 1) * 50);			
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->e.img , map->ppos_y * 50, map->ppos_x * 50);
			}
			else if(check != 1)
			{
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->p.img , map->ppos_y * 50, (map->ppos_x + 1) * 50);			
			}
			map->ppos_x = map->ppos_x + 1;
			check = 0;
			nbr++;
			ft_printf("PM : %d\n", nbr);
		}
	}
	if (key == 124)
	{
		winner_msg(map->map[map->ppos_x][map->ppos_y + 1], map->cpe.c );
		if (map->map[map->ppos_x][map->ppos_y + 1] != '1')
		{
			if (map->map[map->ppos_x][map->ppos_y + 1] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , (map->ppos_y + 1) * 50, map->ppos_x * 50);	
				mlx_put_image_to_window(map->mlx, map->win, map->p_d.img , (map->ppos_y + 1) * 50, map->ppos_x * 50);	
				map->map[map->ppos_x][map->ppos_y + 1] = '0';
				map->cpe.c--;
				check = 1;
			}
			if (map->map[map->ppos_x][map->ppos_y] == 'E')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->p_d.img , (map->ppos_y + 1) * 50, map->ppos_x * 50);	
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->e.img , map->ppos_y * 50, map->ppos_x * 50);
			}
			else if(check != 1)
			{
				mlx_put_image_to_window(map->mlx, map->win, map->p_d.img , (map->ppos_y + 1) * 50, map->ppos_x * 50);	
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
			}
			map->ppos_y = map->ppos_y + 1;
			check = 0;
			nbr++;
			ft_printf("PM : %d\n", nbr);
		}
	}
	if (key == 123)
	{
		winner_msg(map->map[map->ppos_x][map->ppos_y - 1], map->cpe.c);
		if (map->map[map->ppos_x][map->ppos_y - 1] != '1')
		{
			if (map->map[map->ppos_x][map->ppos_y - 1] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , (map->ppos_y - 1) * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->p_a.img , (map->ppos_y - 1) * 50, map->ppos_x * 50);
				map->map[map->ppos_x][map->ppos_y - 1] = '0';
				map->cpe.c--;
				check = 1;
			}
			if (map->map[map->ppos_x][map->ppos_y] == 'E')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->p_a.img , (map->ppos_y - 1) * 50, map->ppos_x * 50);		
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->e.img , map->ppos_y * 50, map->ppos_x * 50);
			}
			else if (check != 1)
			{
				mlx_put_image_to_window(map->mlx, map->win, map->b.img , map->ppos_y * 50, map->ppos_x * 50);
				mlx_put_image_to_window(map->mlx, map->win, map->p_a.img , (map->ppos_y - 1) * 50, map->ppos_x * 50);
			}
			map->ppos_y = map->ppos_y - 1;			
			nbr++;
			check = 0;
			ft_printf("PM : %d\n", nbr);
		}
	}
	return 0;
}

int	close_window(void *param)
{
	(void)param;

	exit(0);
	return (0);
}

void	handle_keys(t_map *map)
{
	mlx_key_hook(map->win, key_callback, (void *)map);
	mlx_hook(map->win, 17, 0, close_window, 0);
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
			handle_keys(&map);
			mlx_loop(map.mlx);
			//while (1);
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	return (0);
}
