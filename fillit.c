/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:09:29 by tbottini          #+#    #+#             */
/*   Updated: 2019/01/16 13:16:18 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_strchri(char *map, int pos)
{
	while (map[pos])
	{
		if (map[pos] == '.')
			return (pos);
		pos++;
	}
	return (-2);
}

int				fillit(t_tetromino **tetros, t_map *map, int n, int t)
{
	int			pos;
	t_map		*map_tmp;

	pos = -1;
	if (!(map_tmp = new_map(map->size)))
		return (-1);
	while ((pos = ft_strchri(map->map, pos + 1)) != -2)
	{
		map_cpy(map_tmp, map);
		if (set_piece(*tetros[n], map_tmp, pos))
		{
			if (n == t - 1 || fillit(tetros, map_tmp, n + 1, t) == -2)
			{
				map_cpy(map, map_tmp);
				del_map(&(map_tmp));
				return (-2);
			}
		}
	}
	pos = -1;
	del_map(&(map_tmp));
	return (0);
}

t_tetromino		**get_tetros(char *trame, int size_lst)
{
	t_tetromino		**tetros;
	int				i;
	char			*part_trame;

	i = 0;
	if (!(tetros = (t_tetromino **)malloc(sizeof(t_tetromino *)
						* (size_lst + 1))))
		return (NULL);
	while (i < size_lst)
	{
		part_trame = &trame[i * 21];
		if (!(tetros[i] = ft_create_tetromino(part_trame, i)))
		{
			tetros_del(tetros);
			return (NULL);
		}
		i++;
	}
	tetros[i] = NULL;
	return (tetros);
}

int				start_ver(int ac)
{
	if (ac == 1 || ac > 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_map		*map;
	t_tetromino	**tetros;
	char		*trame;
	int			ret;
	int			fd;

	if (!start_ver(ac))
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) == -1
		|| !(ret = ft_parseur(fd, &trame))
		|| !(tetros = get_tetros(trame, ret)))
	{
		ft_putendl("error");
		return (-1);
	}
	free(trame);
	if (!(map = new_map(ft_sqrt_up(tetros_active(tetros) * 4))))
		return (-1);
	while (fillit(tetros, map, 0, ret) == 0)
		remap(map);
	ft_putstr(map->map);
	tetros_del(tetros);
	del_map(&map);
	return (0);
}
