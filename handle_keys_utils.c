/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:58:34 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/09 23:02:23 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	winner_msg(char c, t_map *map)
{
	if (c == 'E' && map->cpe.c == 0)
	{
		ft_printf("Congrats you win!\n");
		free_map(map->map);
		exit(0);
	}
}

void	write_pm(t_map *map, int a, int b, int *nbr)
{
	map->check = 0;
	(*nbr)++;
	ft_printf("PM : %d\n", *nbr);
	if (b == 0)
		map->ppos_x = map->ppos_x - a;
	else
		map->ppos_y = map->ppos_y - b;
}

int	close_window(void *param)
{
	t_map *map;

	map = (t_map *)param;
	free(map->map);
	exit(0);
	return (0);
}
