/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:29:36 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 22:36:26 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*element;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		element = ft_lstnew(temp);
		if (!element)
		{
			del(temp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, element);
		lst = lst->next;
	}
	return (new_lst);
}
/*
** ft_lstmap - Aplica a função 'f' a cada elemento da lista 'lst'
 e cria uma nova
** lista com os resultados.
**
** Parâmetros:
** lst: A lista original.
** f: A função a ser aplicada a cada elemento.
** del: A função para deletar o conteúdo de um elemento, 
caso necessário.
**
** Retorna:
** Um ponteiro para a nova lista ou NULL se ocorrer um erro.
*/
