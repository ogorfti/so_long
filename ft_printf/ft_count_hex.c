/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:31:21 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/28 16:03:44 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_hex(unsigned long value)
{
	int	len;

	len = 0;
	while (value)
	{
		value = value / 16;
		len++;
	}
	return (len);
}
