/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:27:03 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/28 16:05:33 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transformers(unsigned int nbr)
{
	char	*curr;
	int		tmp;
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
			curr[i] = tmp + 55;
			i++;
		}
		nbr = nbr / 16;
	}
	curr[i] = '\0';
	return (curr);
}

int	ft_hex2big(unsigned int n)
{
	char	*arr;
	int		len;
	int		j;

	arr = 0;
	j = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	arr = ft_transformers(n);
	len = ft_count_hex(n);
	j = len - 1;
	while (j >= 0)
		ft_putchar(arr[j--]);
	free (arr);
	return (len);
}
