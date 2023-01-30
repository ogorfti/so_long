/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:12:59 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/29 13:00:20 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_formats(va_list args, char format);
int	ft_putstr(char *s);
int	ft_count_dec(long int value);
int	ft_putnbr(long int nbr);
int	ft_unsigned(unsigned int nbr);
int	ft_hex2smallx(unsigned long smallx);
int	ft_hex2big(unsigned int n);
int	ft_void(void *ptr);
int	ft_count_hex(unsigned long value);

#endif