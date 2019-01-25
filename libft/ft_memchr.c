/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:50:13 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/19 04:22:47 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	c1;
	unsigned char	*pos;

	i = 0;
	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	pos = NULL;
	while (i < n && s1[i] != c1)
		i++;
	if (i != n)
		pos = &s1[i];
	return (pos);
}
