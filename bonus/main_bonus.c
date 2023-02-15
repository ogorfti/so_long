/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:41:07 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/15 12:28:12 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_open_door(t_map *map)
{
	if (map->cpex.c <= 1)
	{
		if (map->new_x == map->epos_x && map->new_y == map->epos_y)
			return (1);
	}
	return (0);
}

int	check_name(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)))
		return (0);
	return (1);
}

void	part_bonus(t_map *map)
{
	put_assests(map);
	get_name(map);
	init_coins(map);
	position_of_enemies(map);
	mlx_loop_hook(map->mlx, handle_animation, map);
	handle_keys(map);
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
			part_bonus(&map);
			mlx_loop(map.mlx);
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	return (0);
}
