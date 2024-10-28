/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:33:18 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/07 20:06:32 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *str, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*d;
	size_t	i;

	i = 0;
	d = malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

static void	ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_fillarray(char const *s, char **array, char c)
{
	size_t	i;
	size_t	d;
	size_t	words;

	i = 0;
	d = 0;
	while (i < (size_t)ft_countword(s, c))
	{
		while (s[d] == c)
			d++;
		words = 0;
		while (s[d + words] != '\0' && s[d + words] != c)
			words++;
		array[i] = ft_strndup(&s[d], words);
		if (!array[i])
		{
			ft_free(array);
			return (NULL);
		}
		d = d + words;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_words;
	char	**array;

	n_words = ft_countword(s, c);
	array = malloc(sizeof(char *) * (n_words + 1));
	if (!s || !(array))
		return (NULL);
	array = ft_fillarray(s, array, c);
	if (!array)
	{
		free(array);
		return (NULL);
	}
	return (array);
}

/*
**countword:Função auxiliar para contar o número de 
palavras em uma string
**ft_strndup: Função auxiliar para copiar uma substring de tamanho 
'len' de uma string 's'
**ft_free: Função auxiliar para liberar a memória alocada 
para o array de strings;
**ft_fillarray: Função principal para dividir uma 
string em substrings com base no caractere 'c'
**ft_split: Função principal para dividir uma string em 
substrings com base no caractere 'c'

*/
