/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:39:04 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/06 14:39:09 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/* 
** ft_strrchr - Find the last occurrence of a character
 in a string.
** @s: The string to search.
** @c: The character to locate.
** 
** Returns a pointer to the last occurrence of the character 
'c' in the string 's',
** or NULL if the character is not found.
*/
