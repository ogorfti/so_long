/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:30:02 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/15 12:43:51 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)))
		return (0);
	return (1);
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
		}
	}
	else
		ft_printf("Invalid number of arguments!\n");
	return (0);
}
