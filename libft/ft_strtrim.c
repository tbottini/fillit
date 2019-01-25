/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:30:03 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/19 04:29:27 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_assign(char *s1, char const *s, int j, int i)
{
	int a;

	a = 0;
	while (j <= i)
	{
		s1[a] = s[j];
		a++;
		j++;
	}
	s1[a] = '\0';
}

char		*ft_strtrim(char const *s)
{
	char	*s1;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	s1 = NULL;
	i = (ft_strlen(s) != 0) ? ft_strlen(s) - 1 : ft_strlen(s);
	j = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j] != '\0')
		j++;
	if (i < j)
		i = j + 1;
	if (!(s1 = (char*)malloc(sizeof(char) * (i - j + 2))))
		return (NULL);
	ft_assign(s1, s, j, i);
	return (s1);
}
