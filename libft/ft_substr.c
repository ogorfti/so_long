/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:19:23 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:40:55 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*cnv_s;
	char			*cnv_d;

	i = 0;
	cnv_s = (char *)s;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	cnv_d = (char *)malloc(len + 1);
	if (!cnv_d)
		return (NULL);
	while (i < len && cnv_d)
	{
		cnv_d[i] = cnv_s[start];
		i++;
		start++;
	}
	cnv_d[i] = '\0';
	return (cnv_d);
}
