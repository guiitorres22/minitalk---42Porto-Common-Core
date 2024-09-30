/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:28:10 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 21:30:56 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = (NULL);
	return (element);
}
/*
** Cria um novo elemento da lista com o conteúdo especificado.
** Aloca memória para o elemento e inicializa seus campos.
** Retorna um ponteiro para o novo elemento ou NULL se a alocação falhar.
*/
