/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:24:34 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 22:26:40 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst->next;
	}
}
/*
** Itera sobre a lista ligada 'lst' e aplica a função 'f' a cada elemento.
** A função 'f' recebe um ponteiro para o conteúdo de cada nó da lista.
** Se 'f' ou 'lst' forem nulos, a função retorna sem fazer nada.
*/
