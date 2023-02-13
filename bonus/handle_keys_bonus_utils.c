/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_bonus_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:09 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 17:33:41 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_xpm(t_map *map)
{
	map->p_d.img = mlx_xpm_file_to_image(map->mlx, "textures/p_d.xpm",
			&map->p_d.img_width, &map->p_d.img_height);
	map->p_a.img = mlx_xpm_file_to_image(map->mlx, "textures/p_a.xpm",
			&map->p_a.img_width, &map->p_a.img_height);
	map->p_w.img = mlx_xpm_file_to_image(map->mlx, "textures/p_w.xpm",
			&map->p_w.img_width, &map->p_w.img_height);
	if (!map->p_d.img || !map->p_a.img || !map->p_w.img)
	{
		ft_printf ("Invalid XPM file!\n");
		exit (1);
	}
}

void	winner_msg(char c, t_map *map)
{
	if (c == 'E' && map->cpex.c == 0)
	{
		ft_printf("Congrats you win!\n");
		free_2d(map, 0);
		free_map(map->map);
		exit(0);
	}
}

void	write_pm(t_map *map, int a, int b, int *nbr)
{
	char	*str;

	map->check = 0;
	(*nbr)++;
	str = ft_itoa(*nbr);
	mlx_put_image_to_window(map->mlx, map->win, map->w.img,
		(map->columns * 50) - 100, 0);
	mlx_string_put (map->mlx, map->win,
		(map->columns * 50) - 82, 15, 0x000000, str);
	free (str);
	if (b == 0)
		map->ppos_x = map->ppos_x - a;
	else
		map->ppos_y = map->ppos_y - b;
}

int	close_window(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	free_all (map, 0, 0);
	return (0);
}

void	fbi_open_up(t_map *map)
{
	if (map->cpex.c == 0)
	{
		map->open.img = mlx_xpm_file_to_image(map->mlx, "textures/open.xpm",
				&map->open.img_width, &map->open.img_height);
		mlx_put_image_to_window(map->mlx, map->win, map->open.img,
			map->epos_y * 50, map->epos_x * 50);
	}
}
