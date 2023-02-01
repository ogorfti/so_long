/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:32:56 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/01 23:25:35 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		ppos_x;
	int		ppos_y;
	void	*mlx;
	void	*win;
	t_img	w;
	t_img	p;
	t_img	b;
	t_img	c;
	t_img	e;
}			t_map;

typedef struct s_cpe
{
	int	c;
	int	p;
	int	e;
}	t_cpe;

void    check_map(t_map *map);
void	check_path(t_map *map);


#endif