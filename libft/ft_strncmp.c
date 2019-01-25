/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:57:38 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/15 14:14:18 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while ((s1[i] == s2[i]) && (s1[i] || s2[i]) != '\0' && i < n - 1)
		i++;
	if (n)
		result = *(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i);
	return (result);
}
