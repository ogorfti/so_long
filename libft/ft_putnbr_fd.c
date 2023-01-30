/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:02:27 by ogorfti           #+#    #+#             */
/*   Updated: 2022/10/22 21:38:34 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{	
		ft_putchar_fd('-', fd);
		ft_putchar_fd(2 + '0', fd);
		n = 147483648;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd((n + 48), fd);
	}		
	if (n < 0)
	{
		ft_putchar_fd(('-'), fd);
		ft_putnbr_fd(n * (-1), fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}	
}
