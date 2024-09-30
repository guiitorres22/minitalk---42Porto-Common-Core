/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:06:33 by gtinani-          #+#    #+#             */
/*   Updated: 2024/04/22 17:45:44 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	i = 0;
	if (dl < size)
	{
		while (src[i] && i < (size - 1) - dl)
		{
			dst[dl + i] = src[i];
			i++;
		}
		dst[dl + i] = '\0';
		return (dl + sl);
	}
	else
	{
		return (sl + size);
	}
}
/*
** A função ft_strlcat concatena a string `src` à string `dst`, garantindo que o
** tamanho total da string resultante não exceda `size`.
**
** Parâmetros:
** - `dst`: O ponteiro para a string de destino 
(deve ser grande o suficiente para
**   acomodar a concatenação).
** - `src`: O ponteiro para a string de origem.
** - `size`: O tamanho máximo da string resultante.
**
** Retorno:
** - O comprimento total da string resultante após a concatenação.
**
** Comportamento:
** - Se o comprimento da string `dst` for menor que `size`, a função copia os
**   caracteres de `src` para `dst` até que `size - 1` caracteres tenham sido
**   copiados ou até que o final de `src` seja alcançado. A string resultante é
**   sempre terminada com um caractere nulo.
** - Se o comprimento da string `dst` for maior ou igual a `size`, a função
**   retorna o comprimento total de `src` mais `size`.
*/
