/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:56:45 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/21 21:39:19 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*allocate_smallx(char const *s, char c)
{
	char	*smallx;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	smallx = malloc(len + 1);
	if (!smallx)
		return (0);
	while (i < len)
	{
		smallx[i] = s[i];
		i++;
	}
	smallx[i] = '\0';
	return (smallx);
}

char	**ft_split(char const *s, char c)
{
	char	**big;
	int		i;
	int		j;

	i = 0;
	j = 0;
	big = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!big)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			big[j] = allocate_smallx(&s[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	big[j] = 0;
	return (big);
}
