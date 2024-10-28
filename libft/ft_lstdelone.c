/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:08:31 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/19 22:10:29 by guilherme        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
}
/*
** Remove o nó especificado da lista encadeada.
** O ponteiro 'del' é usado para liberar a memória do conteúdo do nó.
** Em seguida, o próprio nó é liberado com 'free'.
**
** Parâmetros:
** - lst: O nó a ser removido.
** - del: Função para liberar a memória do conteúdo do nó.
*/
