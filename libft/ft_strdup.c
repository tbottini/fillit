/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:00:45 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/26 23:13:24 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = NULL;
	if (!(s2 = (char*)malloc((ft_strlen(s1) + sizeof(char)) * sizeof(char))))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
