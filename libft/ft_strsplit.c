/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:58:29 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/25 03:34:42 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_index(char const *s, char c, unsigned int *index)
{
	int i;
	int	a;
	int index_1;

	index_1 = 0;
	a = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && a == 0)
		{
			index[index_1] = i;
			a = 1;
			index_1++;
		}
		else if (s[i] == c)
			a = 0;
		i++;
	}
}

static void	ft_len(char const *s, char c, size_t *len)
{
	int i;
	int	a;
	int len_1;
	int len_w;

	len_1 = -1;
	a = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && a == 0)
		{
			a = 1;
			len_w = 1;
			len[++len_1] = len_w;
		}
		else if (s[i] == c)
			a = 0;
		else
		{
			len_w++;
			len[len_1] = len_w;
		}
		i++;
	}
}

static void	*ft_free(char **tab_s, size_t *len, int b)
{
	if (b == 1)
		free(tab_s);
	else if (b == 2)
	{
		free(tab_s);
		free(len);
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	*index;
	size_t			*len;
	int				nbr_w;
	char			**tab_s;

	if (s == NULL)
		return (NULL);
	nbr_w = ft_nbr_w(s, c);
	if (!(tab_s = (char**)malloc(sizeof(char*) * (nbr_w + 1))))
		return (NULL);
	if (!(len = (size_t*)malloc(sizeof(size_t) * nbr_w)))
		return (ft_free(tab_s, len, 1));
	if (!(index = (unsigned int*)malloc(sizeof(unsigned int) * nbr_w)))
		return (ft_free(tab_s, len, 2));
	ft_index(s, c, index);
	ft_len(s, c, len);
	tab_s[nbr_w--] = 0;
	while (nbr_w != -1)
	{
		tab_s[nbr_w] = ft_strsub(s, index[nbr_w], len[nbr_w]);
		nbr_w--;
	}
	free(len);
	free(index);
	return (tab_s);
}
