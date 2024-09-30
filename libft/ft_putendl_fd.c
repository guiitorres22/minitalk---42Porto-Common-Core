/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:05:35 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 21:12:56 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
	write(fd, "\n", 1);
}
// Função que escreve uma string seguida de uma quebra
//de linha (newline) em um arquivo descritor (file descriptor).
// Parâmetros:
// - s: Ponteiro para a string que será escrita.
// - fd: O descritor do arquivo onde a string será escrita.
