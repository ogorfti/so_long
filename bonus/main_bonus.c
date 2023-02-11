/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:41:07 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/11 23:40:54 by ogorfti          ###   ########.fr       */
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

int	check_name(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)))
		return (0);
	return (1);
}

void	init_coins(t_map *map)
{
	map->anim.img[0] = mlx_xpm_file_to_image(map->mlx, "textures/c0.xpm",
			&map->anim.img_width, &map->anim.img_height);
	map->anim.img[1] = mlx_xpm_file_to_image(map->mlx, "textures/c1.xpm",
			&map->anim.img_width, &map->anim.img_height);
	map->anim.img[2] = mlx_xpm_file_to_image(map->mlx, "textures/c2.xpm",
			&map->anim.img_width, &map->anim.img_height);
	map->anim.img[3] = mlx_xpm_file_to_image(map->mlx, "textures/c3.xpm",
			&map->anim.img_width, &map->anim.img_height);
	map->anim.img[4] = mlx_xpm_file_to_image(map->mlx, "textures/c4.xpm",
			&map->anim.img_width, &map->anim.img_height);
	map->anim.img[5] = mlx_xpm_file_to_image(map->mlx, "textures/c5.xpm",
			&map->anim.img_width, &map->anim.img_height);
	if (!map->anim.img[0] || !map->anim.img[1] || !map->anim.img[2]
		|| !map->anim.img[3] || !map->anim.img[4] || !map->anim.img[5])
	{
		ft_printf ("There's a problem with XPM files!\n");
		exit (1);
	}
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
	if (keep == 100)
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
			init_coins(&map);
			mlx_loop_hook(map.mlx, handle_animation, &map);
			mlx_loop(map.mlx);
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	return (0);
}
