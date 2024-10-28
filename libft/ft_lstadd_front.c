/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:33:51 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 21:35:56 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
insere um novo elemento no inicio da lista encadeada
ajustando os ponteiros corretamente para manter
a integridadade da lista
-se ambos n forem nulos, o codigo eh executado
-new->next = * lst: O ponteiro next do novo elemento
eh definido como o endereco do prim elemento original
(aposntado por *lst) isso faz com q o novo elemento 
aponte para o antigo primeiro elemento
-*lst = o ponteiro lst (que e um ponteiro para um ponteiro)
eh atualizado para apontar para um novo elemento, tornando-o o
 novo primeiro elemento da lista

*/
