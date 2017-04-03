/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 00:08:23 by vtam              #+#    #+#             */
/*   Updated: 2016/12/03 23:13:09 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# define BUFF_SIZE 21

typedef struct		s_pos{
	int				r;
	int				c;
}					t_pos;

typedef struct		s_map{
	char			**map;
	int				size;
}					t_map;

typedef struct		s_tetris{
	char			**ttmo;
	char			letter;
	struct s_tetris	*next;
}					t_tetris;

int					ft_solve(t_map *tmap, t_tetris *list);
void				ft_place(t_map *tmap, t_pos *tpos, t_tetris *list);
int					ft_check(t_map *tmap, t_pos *tpos, t_tetris *list);
void				ft_tetlstadd(t_tetris **alst, t_tetris *new_ttmo);
t_tetris			*ft_tetlstnew(char **ttmo, char letter);
void				ft_coordinates(t_tetris *list, t_pos *tpos, t_map *tmap);
int					ft_open(char *file, t_tetris **list, int last);
char				**ft_convert(char *str);
char				**ft_initmap(int x);
void				ft_printtet(char **tet);
int					ft_verify(char **tet);
void				ft_normtet(char **tet);
void				ft_place(t_map *tmap, t_pos *tpos, t_tetris *list);
void				ft_remove(char c, t_map *tmap);
void				ft_printmap(t_map *tmap);
#endif
