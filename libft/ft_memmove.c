/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:33:40 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/12 15:59:11 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*dst1;
	char			*src1;

	dst1 = (char*)dst;
	src1 = (char*)src;
	i = 0;
	if (dst < src)
	{
		while (len--)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			dst1[len] = src1[len];
	}
	return (dst1);
}
