/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:00:15 by tbottini          #+#    #+#             */
/*   Updated: 2019/01/16 12:31:55 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*set_map(int len)
{
	char	*map;
	int		i;

	if (!(map = (char *)malloc(sizeof(char) * (len * (len + 1)) + 1)))
		return (NULL);
	i = 1;
	map[len * (len + 1)] = '\0';
	ft_memset((void *)map, '.', len * (len + 1));
	while (map[i - 1])
	{
		if (i % (len + 1) == 0)
		{
			map[i - 1] = '\n';
		}
		i++;
	}
	return (map);
}

void			del_map(t_map **map)
{
	free((*map)->map);
	free(*map);
}

t_map			*remap(t_map *map)
{
	char	*map_tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(map_tmp = set_map(map->size + 1)))
		return (NULL);
	while (map->map[j])
	{
		if ((j + 1) % (map->size + 1) == 0)
		{
			map_tmp[i] = '.';
			i++;
		}
		map_tmp[i] = map->map[j];
		i++;
		j++;
	}
	map->size++;
	free(map->map);
	map->map = map_tmp;
	return (map);
}

t_map			*new_map(int size)
{
	t_map	*new;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(new->map = set_map(size)))
	{
		free((void *)new);
		return (NULL);
	}
	new->size = size;
	return (new);
}

t_map			*map_cpy(t_map *map_dst, t_map *map_src)
{
	ft_strcpy(map_dst->map, map_src->map);
	map_dst->size = map_src->size;
	return (map_dst);
}
