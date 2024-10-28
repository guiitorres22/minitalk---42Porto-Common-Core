/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:55:16 by gtinani-          #+#    #+#             */
/*   Updated: 2024/04/18 16:33:43 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	while (n--)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}
/*
** Função que copia 'n' bytes da memória de 'src'
 para a memória de 'dest'.
** Retorna um ponteiro para 'dest'.
**
** Parâmetros:
**   - dest: Ponteiro para a memória de destino.
**   - src: Ponteiro para a memória de origem.
**   - n: Número de bytes a serem copiados.
**
** Retorno:
**   - Um ponteiro para a memória de destino ('dest').
**   - Se 'dest' ou 'src' forem NULL, retorna NULL.
*/
