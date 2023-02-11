/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:52:54 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/10 17:53:19 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wall_error(void)
{
	ft_printf ("Invalid Wall!\n");
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
		if (i < map->rows)
		{
			if (map->map[i][0] != '1')
				wall_error();
			if (map->map[i][map->columns - 1] != '1')
				wall_error();
		}
		i++;
	}
}
