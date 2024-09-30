/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:40:13 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/07 17:13:44 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*f_str;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	f_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!f_str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		f_str[i++] = s1[start++];
	}
	f_str[i] = '\0';
	return (f_str);
}
/*
** Removes leading and trailing characters from a string.
** The characters to be removed are specified in the
 `set` parameter.
**
** Parameters:
** - `s1`: The input string.
** - `set`: A string containing the characters to trim.
**
** Returns:
** - A new dynamically allocated string with leading and
 trailing characters removed.
** - Returns NULL if `s1` is NULL or if memory allocation fails.
*/
