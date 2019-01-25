/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:12:17 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/08 18:24:51 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;
	char	*s1;

	i = 0;
	c1 = (char)c;
	s1 = (char*)s;
	while (s1[i] != '\0')
		i++;
	while (i != -1)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i--;
	}
	return (NULL);
}
