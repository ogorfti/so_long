/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:36:28 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:36:15 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int value)
{
	int	len;

	len = 0;
	if (value < 0)
	{
		value *= -1;
		len++;
	}
	if (value == 0)
		return (1);
	while (value)
	{
		value = value / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		s;

	s = 0;
	i = get_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		s = 1;
	}
	str[i] = '\0';
	i--;
	while (i >= s)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
