/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:44:05 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/17 22:52:23 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int result;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] || s2[i]) != '\0')
		i++;
	result = *(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i);
	return (result);
}
