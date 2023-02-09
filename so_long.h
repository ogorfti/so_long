/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:32:56 by ogorfti           #+#    #+#             */
/*   Updated: 2023/02/09 23:06:50 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct s_cpe
{
	int	c;
	int	p;
	int	e;
}	t_cpe;

typedef struct s_norme
{
	int	a;
	int	b;
	int	check;
}	t_norme;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		ppos_x;
	int		ppos_y;
	int		epos_x;
	int		epos_y;
	void	*mlx;
	void	*win;
	int		check;
	t_img	w;
	t_img	p;
	t_img	b;
	t_img	c;
	t_img	e;
	t_img	open;
	t_img	p_d;
	t_img	p_a;
	t_img	p_w;
	t_cpe	cpe;
}			t_map;

void	check_map(t_map *map);
void	check_path(t_map *map);
void	free_map(char **map);
void	allocate_map(char *av, t_map *map);
void	put_assests(t_map *map);
void	handle_keys(t_map *map);
int		close_window(void *param);
void	winner_msg(char c, t_map *map);
void	write_pm(t_map *map, int a, int b, int *nbr);
void	check_walls(t_map *map);

#endif