/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:58:34 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/10 16:44:13 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm(t_map *map)
{
	map->p_d.img = mlx_xpm_file_to_image(map->mlx, "textures/p_d.xpm",
			&map->p_d.img_width, &map->p_d.img_height);
	map->p_a.img = mlx_xpm_file_to_image(map->mlx, "textures/p_a.xpm",
			&map->p_a.img_width, &map->p_a.img_height);
	map->p_w.img = mlx_xpm_file_to_image(map->mlx, "textures/p_w.xpm",
			&map->p_w.img_width, &map->p_w.img_height);
}

void	winner_msg(char c, t_map *map)
{
	if (c == 'E' && map->cpe.c == 0)
	{
		ft_printf("Congrats you win!\n");
		free_2d(map, 0);
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
	t_map	*map;

	map = (t_map *)param;
	free_2d(map, 0);
	free(map->map);
	exit(0);
	return (0);
}
