/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:34:17 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/16 19:26:20 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*haystack1;
	char			*needle1;

	needle1 = (char*)needle;
	haystack1 = (char*)haystack;
	i = 0;
	j = 0;
	if (needle1[j] == '\0')
		return (haystack1);
	while (haystack1[i] != '\0' && i < len)
	{
		while (needle1[j] == haystack1[i + j] && (i + j) < len &&
				haystack1[i + j] != '\0')
			j++;
		if (needle1[j] == '\0')
			return (&haystack1[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
