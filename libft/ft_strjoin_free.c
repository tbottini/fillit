/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberramd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:27:20 by yberramd          #+#    #+#             */
/*   Updated: 2018/12/07 17:38:09 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strjoin_free(char **line, char *buffer, int option)
{
	char	*tmp;

	if (option >= 0 && option <= 3)
	{
		if (!buffer && !line)
			return (-1);
		if (option == 2 || option == 3)
			ft_strdel(&buffer);
		if (!(tmp = ft_strjoin(*line, buffer)))
			return (-1);
		if (option == 1 || option == 3)
			ft_strdel(line);
		*line = tmp;
		return (1);
	}
	return (-1);
}
