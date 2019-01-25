/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tetromino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:18:17 by tbottini          #+#    #+#             */
/*   Updated: 2019/01/15 17:51:32 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				min_x_left(t_tetromino *tab)
{
	int a;
	int min;

	a = 0;
	min = 1000;
	while (a < 4)
	{
		if (tab->block[a] % 5 < min)
			min = tab->block[a] % 5;
		a++;
	}
	return (min);
}

t_tetromino		*ft_create_tetromino(char *minimap, int order)
{
	t_tetromino		*elem;
	int				i;
	int				block_nb;
	int				b;

	i = 0;
	block_nb = -1;
	if (!(elem = (t_tetromino *)malloc(sizeof(t_tetromino))))
		return (NULL);
	elem->pose = 0;
	while (i != 21)
	{
		if (minimap[i] == '#')
			elem->block[++block_nb] = i;
		i++;
	}
	b = min_x_left(elem) + (elem->block[0] / 5 * 5);
	block_nb = 0;
	while (block_nb < 4)
	{
		elem->block[block_nb] -= b;
		block_nb++;
	}
	elem->letter = 'A' + order;
	return (elem);
}

int				tetros_active(t_tetromino **tetros)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (tetros[i])
	{
		if (!tetros[i]->pose)
			count++;
		i++;
	}
	return (count);
}

int				set_piece(t_tetromino piece, t_map *map, int pos)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (piece.block[0] > 0 && pos % (map->size + 1) == 0)
		return (0);
	pos -= piece.block[0];
	while (nb < 4)
	{
		i = (piece.block[nb] / 5) * (map->size + 1) + piece.block[nb] % 5;
		if (map->map[pos + i] != '.' || pos + i > (map->size * (map->size + 1)))
			return (0);
		nb++;
	}
	nb = 0;
	while (nb < 4)
	{
		(map->map)[pos + (piece.block[nb] / 5) *
			(map->size + 1) + piece.block[nb] % 5] = piece.letter;
		nb++;
	}
	return (map->size);
}

void			tetros_del(t_tetromino **tetros)
{
	int i;

	i = 0;
	while (tetros[i] != NULL)
	{
		free(tetros[i]);
		i++;
	}
	free(tetros);
}
