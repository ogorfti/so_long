/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:13:12 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/29 12:58:51 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_nope(char *oldline)
{
	char	*newline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (oldline[i] != '\n' && oldline[i])
		i++;
	if (oldline[i] == '\n')
		i++;
	newline = malloc (i + 1);
	while (j < i)
	{
		newline[j] = oldline[j];
		j++;
	}
	newline[j] = '\0';
	if (*newline == 0)
	{
		free (newline);
		return (0);
	}
	return (newline);
}

char	*get_shyata(char *line)
{
	char	*shyata;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] != '\n')
	{
		free(line);
		return (NULL);
	}
	i++;
	shyata = malloc(ft_strlen1(line) - i + 1);
	while (line[i])
	{
		shyata[j] = line[i];
		j++;
		i++;
	}
	shyata[j] = '\0';
	free (line);
	return (shyata);
}

char	*get_line_with_shyata(int fd, char *joiner)
{
	char	*buffer;
	int		checker;

	checker = 1;
	if (!joiner)
		joiner = ft_calloc1(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	while (checker != 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker <= 0)
			break ;
		buffer[checker] = '\0';
		joiner = ft_strjoin1(joiner, buffer);
		if (ft_strchr1(joiner, '\n'))
			break ;
	}
	free (buffer);
	return (joiner);
}

char	*get_next_line(int fd)
{
	static char	*shyata;
	char		*line;
	char		*oldline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	oldline = get_line_with_shyata(fd, shyata);
	line = get_line_nope(oldline);
	shyata = get_shyata(oldline);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
//         int fd;
//         char *line;
//             //fd = open(av[1], O_RDONLY,O_WRONLY);
//             fd = open("test.txt", O_RDONLY);
//             //if (fd == -1)
//                 //printf("error");
//         line = get_next_line(fd);
//         printf ("%s", line);
//         //line = get_next_line(1);
//         //printf("%s", line);
//         //line = get_next_line(fd);
//        //printf ("%d", BUFFER_SIZE);

// }