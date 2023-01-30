/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:58:41 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:38:05 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cnv_dst;
	const char	*cnv_src;

	cnv_src = src;
	cnv_dst = dst;
	if (cnv_dst > cnv_src)
	{
		while (len)
		{
			cnv_dst[len - 1] = cnv_src[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(cnv_dst, cnv_src, len);
	return (cnv_dst);
}
