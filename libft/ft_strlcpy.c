/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:25:00 by gtinani-          #+#    #+#             */
/*   Updated: 2024/04/26 18:00:37 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_l;
	size_t	cpy_l;

	i = 0;
	src_l = ft_strlen(src);
	if (size == 0)
		return (src_l);
	cpy_l = size - 1;
	if (src_l < cpy_l)
		cpy_l = src_l;
	while (i < cpy_l)
	{
		dst[i] = src[i];
		i++;
	}
	dst[cpy_l] = '\0';
	return (src_l);
}
/*
** Copia uma string da origem (src) para o destino (dst)
 com um tamanho máximo
** especificado (size).
**
** Parâmetros:
** - dst: Ponteiro para o buffer de destino 
(onde a string será copiada).
** - src: Ponteiro para a string de origem 
(a ser copiada).
** - size: Tamanho máximo do buffer de destino.
**
** Retorno:
** - Retorna o comprimento da string de origem (src).
**
** Observações:
** - Se o tamanho (size) for 0, apenas o comprimento
 da string de origem é retornado.
** - O buffer de destino (dst) deve ter 
espaço suficiente para a cópia.
** - A função não adiciona um caractere nulo 
ao final do buffer de destino se o tamanho
**   for menor que o comprimento da string de origem.
*/
