/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:41:57 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/21 16:21:27 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len(long n, int neg)
{
	long i;

	i = 0;
	if (n == 0)
		i = 2;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (neg == 0)
		i--;
	return (i);
}

static void	ft_nbr(char *nbr, int neg, int len, long n)
{
	int i;

	i = 0;
	if (n == 0)
		len--;
	if (neg == 1)
	{
		nbr[i] = '-';
		i++;
	}
	nbr[len + 1] = '\0';
	while (n > 0)
	{
		nbr[len] = (n % 10) + 48;
		len--;
		n = n / 10;
	}
	if (neg == 0)
		nbr[len] = (n % 10) + 48;
}

char		*ft_itoa(int n)
{
	char			*nbr;
	int				neg;
	int				len;
	int				int_max;
	long			n1;

	neg = 0;
	int_max = 0;
	n1 = n;
	if (n1 < 0)
	{
		n1 = -n1;
		neg++;
	}
	len = ft_len(n1, neg);
	if (!(nbr = (char*)malloc(sizeof(char) * (len + neg) + 1)))
		return (NULL);
	ft_nbr(nbr, neg, len, n1);
	return (nbr);
}
