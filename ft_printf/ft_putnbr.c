/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <marvin@42.fr>                   +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:17:35 by guilherme         #+#    #+#             */
/*   Updated: 2024/06/28 19:31:53 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	int	c;

	c = 0;
	if (nb == -2147483648)
	{
		c += ft_putstr("-2147483648");
	}
	else
	{
		if (nb < 0)
		{
			c += ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			c += ft_putnbr(nb / 10);
		}
		c += ft_putchar(nb % 10 + '0');
	}
	return (c);
}
