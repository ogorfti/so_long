/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:16:31 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/29 12:59:41 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//va_list : is a type to hold information about variable arguments.

//va_start : connect our argument list with someArgumentPointer.

//va_arg : This function returns the value of the argument pointed
//by ap, and also update the ap to point to the next argument in the list.

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_formats(ap, str[i]);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
