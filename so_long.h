/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:32:56 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/30 12:06:18 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		ppos_x;
	int		ppos_y;
}			t_map;

typedef struct s_cpe
{
	int	c;
	int	p;
	int	e;
}	t_cpe;

typedef struct s_ppos
{
}	t_ppos;

void	check_map(int ac, char *av, t_map *map);

#endif