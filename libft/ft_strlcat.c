/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:13:15 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/15 17:03:02 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	k;
	unsigned int	i;
	unsigned int	j;
	unsigned int	result;

	if (!(size))
		return (ft_strlen(src));
	k = ft_strlen(dst);
	if (size <= k)
		return (ft_strlen(src) + size);
	i = ft_strlen(dst);
	j = 0;
	while ((i < size - 1) && (src[j] != '\0'))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	result = k + ft_strlen(src);
	dst[i] = '\0';
	return (result);
}
