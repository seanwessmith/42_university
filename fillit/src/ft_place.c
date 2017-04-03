/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:39:25 by vtam              #+#    #+#             */
/*   Updated: 2016/12/03 17:13:43 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(t_map *tmap, t_pos *tpos, t_tetris *list)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (list->ttmo[i][j] == '#' && (i + tpos->r)
					< tmap->size && (j + tpos->c) < tmap->size)
			{
				if (tmap->map[tpos->r + i][tpos->c + j] != '.')
					return (0);
			}
			else if (list->ttmo[i][j] == '#')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_printmap(t_map *tmap)
{
	int		r;
	int		c;

	r = 0;
	c = 0;
	while (r < tmap->size)
	{
		c = 0;
		while (c < tmap->size)
		{
			ft_putchar(tmap->map[r][c]);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

void	ft_place(t_map *tmap, t_pos *tpos, t_tetris *list)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (list->ttmo[i][j] == '#')
			{
				if ((i + tpos->r) < tmap->size && (j + tpos->c) < tmap->size)
					tmap->map[i + tpos->r][j + tpos->c] = list->letter;
			}
			j++;
		}
		i++;
	}
}

void	ft_remove(char c, t_map *tmap)
{
	int		i;
	int		j;

	i = 0;
	while (i < tmap->size)
	{
		j = 0;
		while (j < tmap->size)
		{
			if (tmap->map[i][j] == c)
				tmap->map[i][j] = '.';
			j++;
		}
		i++;
	}
}
