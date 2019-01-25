/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:34:07 by yberramd          #+#    #+#             */
/*   Updated: 2018/11/19 04:21:01 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*memoire;

	if (!(memoire = (void*)malloc(sizeof(void*) * size)))
		return (NULL);
	ft_bzero(memoire, size);
	return (memoire);
}
