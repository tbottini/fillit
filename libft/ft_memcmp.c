/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:30:09 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/19 04:22:50 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	int				result;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	result = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if ((str1 == NULL && n == 0) || (str2 == NULL && n == 0))
		return (0);
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	if (i == n)
		return (result);
	result = str1[i] - str2[i];
	return (result);
}
