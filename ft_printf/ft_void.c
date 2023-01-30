/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:49 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/28 15:44:22 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_void(void *ptr)
{
	int	len;

	len = 0;
	write(1, "0x", 2);
	len = 2 + ft_hex2smallx((unsigned long)ptr);
	return (len);
}
