/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:27:10 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/14 15:09:22 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*haystack1;
	char	*needle1;

	needle1 = (char*)needle;
	haystack1 = (char*)haystack;
	i = 0;
	j = 0;
	if (needle1[j] == '\0')
		return (haystack1);
	while (haystack1[i] != '\0')
	{
		j = 0;
		while (needle1[j] == haystack1[i + j])
		{
			j++;
			if (needle1[j] == '\0')
				return (&haystack1[i]);
		}
		i++;
	}
	return (NULL);
}
