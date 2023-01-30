/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:42:08 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/28 15:46:38 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if ((format == 'd') || (format == 'i'))
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_hex2big(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_hex2smallx(va_arg(args, unsigned int));
	else if (format == 'p')
		len += ft_void(va_arg(args, void *));
	else
		len += ft_putchar(format);
	return (len);
}
