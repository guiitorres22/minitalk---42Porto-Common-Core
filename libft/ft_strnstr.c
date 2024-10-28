/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:18:29 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/04 22:52:07 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
** A função ft_strnstr procura a primeira ocorrência 
da string 'little' dentro da
** string 'big', mas apenas nos primeiros
 'len' caracteres de 'big'.
**
** Parâmetros:
** - big: A string na qual procuramos.
** - little: A string que estamos buscando.
** - len: O número máximo de caracteres a serem verificados.
**
** Retorno:
** - Se 'little' for uma string vazia, retorna um
 ponteiro para 'big'.
** - Caso contrário, procura por 'little' em 'big'
 e retorna um ponteiro para a
**   primeira ocorrência de 'little' dentro dos primeiros 
'len' caracteres de 'big'.
**   Se não encontrar, retorna NULL.
*/
