/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbottini <tbottini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:52:47 by tbottini          #+#    #+#             */
/*   Updated: 2019/01/15 14:37:34 by tbottini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetromino
{
	int			block[4];
	char		pose;
	char		letter;
	char		d_encr;

}				t_tetromino;

typedef struct	s_map
{
	char		*map;
	int			size;
}				t_map;

t_tetromino		*ft_create_tetromino(char *minimap, int order);
void			ft_print_tetromino(t_tetromino piece);
int				set_piece(t_tetromino piece, t_map *map, int pos);
void			tetros_del(t_tetromino **tetros);
int				tetros_active(t_tetromino **tetros);
t_tetromino		**get_tetros(char *trame, int size_lst);
int				piece_counter(char **trame, int fd);
int				sqrt_up(int nb);
t_map			*new_map(int size);
t_map			*remap(t_map *map);
int				get_diaposition(t_map *map, int pos, int *decalage);
void			del_map(t_map **map);
char			*set_map(int len);
t_map			*map_cpy(t_map *map_dst, t_map *map_src);
int				get_lin_position(t_map *map, int pos);
int				ft_strchri(char *map, int pos);
int				ft_parseur(int fd, char **file);

#endif
