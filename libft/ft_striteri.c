/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:21:54 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/08 21:22:11 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
** ft_striteri: Aplica uma função a cada caractere de uma string, 
passando o índice e o próprio caractere como argumentos.
**
** Parâmetros:
** - s: A string a ser percorrida.
** - f: O ponteiro para a função que será aplicada a cada caractere.
**
** Comportamento:
** - A função percorre a string 's' e, para cada caractere,
 chama a função 'f' passando o índice e o caractere como argumentos.
** - O índice começa em 0 para o primeiro caractere e aumenta a cada iteração.
**
** Exemplo de uso:
** ```
** void print_char_index(unsigned int index, char *c)
** {
**     printf("Caractere na posição %u: %c\n", index, *c);
** }
**
** int main(void)
** {
**     char str[] = "Hello, world!";
**     ft_striteri(str, &print_char_index);
**     return 0;
** }
** ```
** Isso imprimirá:
** ```
** Caractere na posição 0: H
** Caractere na posição 1: e
** Caractere na posição 2: l
** ...
** ```
*/
