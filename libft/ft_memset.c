/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:42:34 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/06 18:18:22 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		n--;
	}
	return (s);
}
/*
** Preenche os primeiros 'n' bytes da área de memória 
apontada por 's' com o valor 'c'.
**
** Parâmetros:
** - s: Ponteiro para a área de memória a ser preenchida.
** - c: Valor a ser preenchido (convertido para unsigned char).
** - n: Número de bytes a serem preenchidos.
**
** Retorno:
** - Retorna o ponteiro original 's'.
**
** Observações:
** - Ela é frequentemente usada para inicializar buffers 
de memória com um valor específico.
** - O ponteiro 's' deve apontar para uma área de memória 
válida com pelo menos 'n' bytes.
** - O valor 'c' é convertido para unsigned char para garantir 
que seja tratado como um byte.
** - A função itera sobre os 'n' bytes, preenchendo cada
 um com o valor 'c'.
*/
