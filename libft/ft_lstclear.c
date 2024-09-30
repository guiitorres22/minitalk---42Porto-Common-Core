/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:13:51 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 22:16:50 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*element;
	t_list	*next;

	if (!lst || !del)
		return ;
	element = *lst;
	while (element)
	{
		next = element->next;
		del(element->content);
		free(element);
		element = next;
	}
	*lst = NULL;
}
/*
** Libera a memória alocada por uma lista encadeada.
** A função recebe um ponteiro para o ponteiro da lista (lst) e um ponteiro
** para uma função que libera a memória do conteúdo de cada elemento (del).
** Ela percorre a lista, libera a memória de cada elemento e, em seguida,
** define o ponteiro da lista como NULL.
*/
