/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:39:34 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/13 16:34:32 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_msg(void)
{
	ft_printf("Invalid MAP!\n");
	exit (1);
}

void	check_display(t_map *map, int rows, int columns)
{
	if (rows > 28 || columns > 51)
	{
		ft_printf("Invalid Map Size!\n");
		free_map (map->map);
		exit (1);
	}	
}

void	allocate_map(char *av, t_map *map)
{
	char	*joiner;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		invalid_msg();
	joiner = ft_calloc1(1, 1);
	map->rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line && map->rows == 0)
			invalid_msg();
		if (!line)
			break ;
		joiner = ft_strjoin1(ft_strjoin1(joiner, " "), line);
		map->rows++;
		free (line);
	}
	joiner = ft_strjoin1(joiner, "\n");
	map->map = ft_split(joiner, ' ');
	free (joiner);
	map->columns = ft_strlen1(map->map[0]) - 1;
	check_display(map, map->rows, map->columns);
}
