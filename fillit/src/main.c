/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 23:59:07 by vtam              #+#    #+#             */
/*   Updated: 2016/12/03 21:02:08 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solve(t_map *tmap, t_tetris *list)
{
	t_pos	tpos;
	int		placed;

	placed = 0;
	if (list == NULL)
		return (1);
	tpos.r = -1;
	while (++tpos.r < tmap->size && placed == 0 && (tpos.c = -1))
		while (++tpos.c < tmap->size && placed == 0)
			if (ft_check(tmap, &tpos, list) == 1)
			{
				placed = 1;
				ft_place(tmap, &tpos, list);
				if (ft_solve(tmap, list->next) == 1)
					return (1);
				else
				{
					ft_remove(list->letter, tmap);
					placed = 0;
				}
			}
	if (placed == 0 && tpos.r == tmap->size && tpos.c == tmap->size)
		return (0);
	return (1);
}

void	ft_coordinates(t_tetris *list, t_pos *tpos, t_map *tmap)
{
	t_tetris *cur;

	cur = list;
	while (cur != NULL && (tpos->c = 0))
	{
		while (tpos->c < 4)
		{
			tpos->r = 0;
			while (cur->ttmo[tpos->c][tpos->r])
				tpos->r++;
			tpos->c++;
		}
		cur = cur->next;
	}
	tmap->size = 1;
	tmap->map = ft_initmap(tmap->size);
}

int		main(int argc, char **argv)
{
	t_map		tmap;
	t_pos		tpos;
	t_tetris	*list;

	list = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit sample_file\n");
		return (1);
	}
	if (ft_open(argv[1], &list, 0) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	ft_coordinates(list, &tpos, &tmap);
	while (ft_solve(&tmap, list) == 0 && tmap.size++)
		tmap.map = ft_initmap(tmap.size);
	ft_printmap(&tmap);
	return (0);
}
