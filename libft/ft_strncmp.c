/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:09:26 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:40:26 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cnv_s1;
	unsigned char	*cnv_s2;

	i = 0;
	cnv_s1 = (void *) s1;
	cnv_s2 = (void *) s2;
	while ((cnv_s1[i] != '\0' || cnv_s2[i] != '\0') && i < n)
	{
		if (cnv_s1[i] < cnv_s2[i])
			return (-1);
		else if (cnv_s1[i] > cnv_s2[i])
			return (1);
		i++;
	}
	return (0);
}
