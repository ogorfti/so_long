/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:14:45 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:39:56 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The strlcat() function appends the 
//NUL-terminated string src to the end of dst. 
//It will append at most size - strlen(dst) - 1 bytes,
// NUL-terminating the result.

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	if (dstsize == 0 && dst == NULL)
		return (ft_strlen(src));
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	j = len_d;
	if (dstsize <= len_d)
		return (dstsize + len_s);
	while (src[i] != '\0' && i < dstsize - len_d - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_d + len_s);
}
