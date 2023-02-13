make fclean
make bonus
make clean
./so_long_bonus maps/map_bonus.ber

# // void	get_name(t_map *map)
# //{
# // 	char	*joiner;
# // 	char	*line;
# // 	int		fd;

# // 	joiner = ft_calloc1(1, 1);
# // 	fd = open ("coins.txt", O_RDONLY);
# // 	if (fd == -1)
# // 	{
# // 		ft_printf("There's a problem with FD!\n");
# // 		exit (1);
# // 	}
# // 	while (1)
# // 	{
# // 		line = get_next_line(fd);
# // 		if (!line)
# // 			break ;
# // 		joiner = ft_strjoin1(joiner, line);
# // 		free(line);
# // 	}
# // 	map->coins = ft_split(joiner, '\n');
# // 	free (joiner);
# // }