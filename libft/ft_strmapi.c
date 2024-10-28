/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:41:09 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/08 20:05:52 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
** A função ft_strmapi aplica a função f 
a cada caractere da string s.
** Ela passa o índice do caractere 
na string e o próprio caractere para a função f.
** O resultado da função f é colocado na
 nova string no índice i.
** No final, retornamos a nova string resultante da 
aplicação de f a cada caractere da string.
*/
