/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:23:46 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/16 17:08:24 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		neg;

	i = 0;
	nbr = 0;
	neg = -1;
	while (str[i] <= 32 && str[i] != 27 && str[i] >= 0)
		i++;
	if (str[i] == '-')
		neg = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) - (str[i] - 48);
		i++;
	}
	if (neg == -1)
		return (nbr * neg);
	return (nbr);
}
