/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:46:53 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/11 15:33:31 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_cpex
{
	int	c;
	int	p;
	int	e;
	int	x;
}	t_cpex;

typedef struct s_map
{
	t_cpex	cpex;
	char	**map;
	int		rows;
	int		columns;
	int		ppos_x;
	int		ppos_y;
	int		epos_x;
	int		epos_y;
	void	*mlx;
	void	*win;
	t_img	w;
	t_img	p;
	t_img	b;
	t_img	c;
	t_img	e;
	t_img	x;
}			t_map;

void	allocate_map(char *av, t_map *map);
void	check_map(t_map *map);
void	free_map(char **map);
void	check_walls(t_map *map);
void	check_path(t_map *map);
void	put_assests(t_map *map);

#endif