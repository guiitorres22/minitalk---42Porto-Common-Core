/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:20:25 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/07 16:00:29 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*nstr;

	if (!s || start >= ft_strlen(s))
	{
		nstr = (char *)malloc(sizeof(char));
		if (!nstr)
			return (NULL);
		nstr[0] = '\0';
		return (nstr);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		nstr[i] = s[start + i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
/* 
** The `ft_substr` function creates a new string by extracting 
a substring from the input string `s`.
** The substring starts at the specified `start` index and has a
 maximum length of `len`.
** If `s` is NULL or `start` is out of bounds, it returns an empty string.
** Otherwise, it allocates memory for the new substring, copies the
 characters, and terminates it with a null character.
*/
