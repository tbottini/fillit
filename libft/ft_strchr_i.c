/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:38:58 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/26 21:40:14 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_i(const char *s, int c)
{
	int		i;
	char	c1;
	char	*s1;

	i = 0;
	c1 = (char)c;
	s1 = (char*)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == c1)
			return (i);
		i++;
	}
	if (s1[i] == c1)
		return (i);
	return (-1);
}
