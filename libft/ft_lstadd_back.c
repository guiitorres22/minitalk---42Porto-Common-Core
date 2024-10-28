/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:50:32 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 22:04:26 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	if (!last)
	{
		*lst = new;
		return ;
	}
	while (last -> next)
		last = last->next;
	last->next = new;
}
/*Aduciona um elemento ao final de uma 
lista encadeada
recebe 2 args, lst, ponteiro para inicio da lista,
 new,
ponteiro para novo elemento.
-Verifica de os ponteiros sao nulos
-Inicialista las com o valor apontado por lst
-Verifica se a lista ta vazia, se sim, o ponteiro da 
cabeca da lista e
atualizado para apontar para o new
-(while last->next)percorre a lista ate encontrar o 
ultimo elemento (onde last->next)
-last->next = new,  atualiza o ponteiro next do 
ultimo elemento para apontar para o new*/
