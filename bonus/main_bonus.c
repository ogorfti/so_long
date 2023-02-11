/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:41:07 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/11 15:33:50 by ogorfti          ###   ########.fr       */
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
		ft_printf("  %s", map[i]);
		i++;
	}
}

int	check_name(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)))
		return (0);
	return (1);
}

// void	handle_animation(t_map *map)
// {
	
// }

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
			//mlx_loop_hook(map.map, handle_animation, (void *)map.map);
			mlx_loop(map.mlx);
			//display_map(map.map);
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	return (0);
}