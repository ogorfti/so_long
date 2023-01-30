/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:04:17 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/29 19:50:21 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	saver;

	i = 0;
	j = 0;
	saver = 0;
	if (len == 0 && (char *)haystack == NULL)
		return (0);
	while (haystack[i] && needle [j] && i < len)
	{
		if (haystack[i] == needle[j])
			j++;
		else
		{
			j = 0;
			i = 0 + saver;
			saver++;
		}
			i++;
	}
	if (ft_strlen(needle) == j)
		return ((char *)&haystack[i - ft_strlen(needle)]);
	return (NULL);
}
