/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2smallx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:30:19 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/28 16:15:52 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transformersx(unsigned long nbr)
{
	int		tmp;
	char	*curr;
	int		i;

	i = 0;
	curr = malloc(ft_count_hex(nbr) + 1);
	while (nbr != 0)
	{
		tmp = nbr % 16;
		if (tmp < 10)
		{
			curr[i] = tmp + 48;
			i++;
		}
		else
		{
			curr[i] = tmp + 87;
			i++;
		}
		nbr = nbr / 16;
	}
	curr[i] = '\0';
	return (curr);
}

int	ft_hex2smallx(unsigned long smallx)
{
	char	*arr;
	int		j;
	int		len;

	j = 0;
	arr = 0;
	len = 0;
	if (smallx == 0)
	{
		ft_putchar('0');
		return (1);
	}
	arr = ft_transformersx(smallx);
	len = ft_count_hex(smallx);
	j = len - 1;
	while (j >= 0)
		ft_putchar(arr[j--]);
	free(arr);
	return (len);
}
