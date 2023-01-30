/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:42:35 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:47:43 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tar;

	i = 0;
	tar = NULL;
	if (s)
		tar = ft_strdup(s);
	if (tar)
	{
		while (tar[i])
		{
			tar[i] = f(i, tar[i]);
			i++;
		}
	}
	return (tar);
}
