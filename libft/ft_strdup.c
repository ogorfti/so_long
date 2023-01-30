/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:24:19 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:38:54 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*target;
	size_t	i;

	i = 0;
	target = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!target)
		return (NULL);
	while (s1[i] != '\0')
	{
		target[i] = ((char *)s1)[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
