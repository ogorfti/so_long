/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:43:11 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:37:47 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cnv_s;

	i = 0;
	cnv_s = (unsigned char *)s;
	while (i < n)
	{
		if (cnv_s[i] == (unsigned char)c)
		{
			return (&cnv_s[i]);
		}
		i++;
	}
	return (NULL);
}
