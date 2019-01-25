/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:53:23 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/26 21:32:58 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strnclr(char *s, size_t length)
{
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		while (i < length)
		{
			s[i] = '\0';
			i++;
		}
	}
}
