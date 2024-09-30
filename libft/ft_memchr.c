/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:23:07 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/06 13:42:31 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
/*
** Function: ft_memchr
** --------------------
** Locates the first occurrence of the character 'c' (interpreted as an
** unsigned char) in the initial 'n' bytes of the memory area pointed to by 's'.
**
** s: A pointer to the memory area to search.
** c: The character to search for.
** n: The number of bytes to search.
**
** Returns: A pointer to the first occurrence of 'c' in the memory area 's',
**          or NULL if 'c' is not found.
*/
