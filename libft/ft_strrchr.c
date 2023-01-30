/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:56:57 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:40:39 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;
	int	d;
	int	ctr;

	i = 0;
	j = 0;
	d = 0;
	ctr = 0;
	while (s[ctr] != '\0')
		ctr++;
	while (i <= ctr)
	{
		if (s[i] == (char)c)
		{
			d++;
			j = i;
		}
		i++;
	}
	if (d > 0)
		return ((char *)&s[j]);
	return (0);
}
