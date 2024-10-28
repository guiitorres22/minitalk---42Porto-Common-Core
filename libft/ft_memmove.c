/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:40:04 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/06 18:15:54 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
** A função ft_memmove copia 'n' bytes da string 'src' para a string 'dest'.
** Ela lida com casos em que as duas strings podem se sobrepor.
** O objetivo é sempre fazer a cópia de forma não destrutiva.
**
** Parâmetros:
** - dest: ponteiro para a área de memória de destino
** - src: ponteiro para a área de memória de origem
** - n: número de bytes a serem copiados
**
** Retorno:
** - Retorna o ponteiro para a área de memória de destino
 (ou NULL em caso de erro)
*/
