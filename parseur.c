/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:44:14 by yberramd          #+#    #+#             */
/*   Updated: 2019/01/15 17:51:48 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_square(char *tab)
{
	int i;
	int nbr_chr;
	int nbr_new_l;

	i = 0;
	nbr_new_l = 0;
	nbr_chr = 0;
	while (tab[i] != '\0')
	{
		while (tab[i] != '\n')
		{
			nbr_chr++;
			if (tab[i] != '.' && tab[i] != '#')
				return (0);
			i++;
		}
		if (nbr_chr % 4 != 0)
			return (0);
		nbr_new_l++;
		i++;
	}
	if (nbr_chr != 16 && nbr_new_l != 5)
		return (0);
	return (1);
}

static int		count_connections(char *tab, int i)
{
	int nbr_co;

	nbr_co = 0;
	if ((i % 5) != 0)
		if (tab[i - 1] == '#')
			nbr_co++;
	if (i > 4)
		if (tab[i - 5] == '#')
			nbr_co++;
	if (i < 14)
		if (tab[i + 5] == '#')
			nbr_co++;
	if ((i % 5) != 3)
		if (tab[i + 1] == '#')
			nbr_co++;
	return (nbr_co);
}

static int		ft_tetriminos(char *tab)
{
	int i;
	int connections;
	int nbr_p;

	i = 0;
	nbr_p = 0;
	connections = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '#')
		{
			connections += count_connections(tab, i);
			nbr_p++;
		}
		i++;
	}
	return ((connections >= 6 && nbr_p == 4) ? 1 : 0);
}

static int		ft_last(char *tab)
{
	int i;
	int new_l;

	new_l = 0;
	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '\n')
			new_l++;
		i++;
	}
	return ((new_l == 4) ? 1 : 0);
}

int				ft_parseur(int fd, char **file)
{
	int		ret;
	int		nbr_p;
	char	tab[BUFF_SIZE + 1];

	nbr_p = 0;
	if (!(*file = ft_strnew(0)))
		return (0);
	while ((ret = read(fd, tab, BUFF_SIZE)) > 0)
	{
		tab[ret] = '\0';
		if (!ft_square(tab) || !ft_tetriminos(tab))
		{
			free(*file);
			return (0);
		}
		ft_strjoin_free(file, tab, 1);
		nbr_p++;
	}
	if (!ft_last(tab))
	{
		free(*file);
		return (0);
	}
	return (nbr_p);
}
