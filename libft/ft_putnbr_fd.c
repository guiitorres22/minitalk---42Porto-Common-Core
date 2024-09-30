/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:18:04 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 21:26:02 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	res;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr_fd(nb / 10, fd);
		}
		res = nb % 10 + '0';
		write(fd, &res, 1);
	}
}
// Função para imprimir um número inteiro em um descritor de arquivo (fd)
//res Variável para armazenar o dígito convertido
// Verifica se o número é o mínimo possível (-2147483648)
// Se o número for negativo Escreve o caractere '-' no arquivo
// Transforma o número em positivo
// Se o número for maior ou igual a 10
// Calcula o dígito atual e converte para caractere
// Escreve o dígito no arquivo
