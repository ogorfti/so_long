/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:13 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/30 18:50:00 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr1(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&s[i]);
}

void	*ft_calloc1(size_t nitems, size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	if (nitems >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	arr = malloc(nitems * size);
	if (!arr)
		return (NULL);
	while (i < nitems * size)
		arr[i++] = '\0';
	return (arr);
}

char	*ft_strjoin1(char *str1, char *str2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	if (!str1 || !str2)
		return (NULL);
	join = malloc(ft_strlen1 (str1) + ft_strlen1 (str2) + 1);
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		join[i++] = str2[j++];
	join[i] = '\0';
	free (str1);
	return (join);
}

// int main()
// {
// 	char *s1 = "\0";
// 	char *s2 = "gorfti";
// 	printf("%s\n", ft_strjoin(s1, s2));
// }