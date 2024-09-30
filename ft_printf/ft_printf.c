/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:38:08 by guilherme         #+#    #+#             */
/*   Updated: 2024/09/28 16:42:40 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_specifier(char spec, va_list arg)
{
	int	c;

	c = 0;
	if (spec == 'c')
		c += ft_putchar(va_arg(arg, int));
	else if (spec == 's')
		c += ft_putstr(va_arg(arg, char *));
	else if (spec == 'p')
		c += ft_putpointer(va_arg(arg, unsigned long));
	else if (spec == 'i' || spec == 'd')
		c += ft_putnbr(va_arg(arg, int));
	else if (spec == 'u')
		c += ft_putuns(va_arg(arg, unsigned int));
	else if (spec == 'x')
		c += ft_puthex(va_arg(arg, unsigned int), 'x');
	else if (spec == 'X')
		c += ft_puthex(va_arg(arg, unsigned int), 'X');
	else if (spec == '%')
		c += ft_putchar('%');
	return (c);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		c;

	c = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			c += format_specifier(*format, arg);
		}
		else
		{
			c += ft_putchar(*format);
		}
		++format;
	}
	va_end(arg);
	return (c);
}