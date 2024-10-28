/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:25:29 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/28 16:44:09 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	if ((long int)n == 0)
		return (ft_strdup("0"));
	if ((long int)n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_intlen((long int)n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if ((long int)n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while ((long int)n > 0)
	{
		str[i] = 48 + ((long int)n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}