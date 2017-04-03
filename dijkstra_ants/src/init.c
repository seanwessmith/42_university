/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:59:34 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/24 18:29:48 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	init_lemin(t_lemin *lemin, int type)
{
	int		i;

	i = -1;
	if (type == 0)
	{
		lemin->moves = 0;
		lemin->start = 0;
		lemin->end = 0;
		lemin->startend = 0;
		lemin->r_ct = 0;
		lemin->t_ct = 0;
		lemin->finished = 0;
		lemin->ants = (int **)malloc(sizeof(int *) * lemin->ant_count);
	}
	else
	{
		while (++i < lemin->ant_count)
		{
			lemin->ants[i] = (int *)malloc(sizeof(int) * 3);
			lemin->ants[i][0] = lemin->start;
			lemin->ants[i][1] = 0;
			lemin->ants[i][2] = 0;
		}
	}
}

void	parse_hash(char *str, t_lemin *lemin)
{
	if (ft_strequ(str, "##start"))
	{
		lemin->start = -1;
		lemin->startend++;
	}
	else if (ft_strequ(str, "##end"))
	{
		lemin->end = -1;
		lemin->startend++;
	}
}

int		parse_numstr(char *str, int i)
{
	int		num;

	num = 0;
	while (*str && !(i == 0 && (*str == ' ' || *str == '-')))
	{
		if (i == 0)
		{
			num *= 10;
			num += (*str - '0');
		}
		if (*str == ' ' || *str == '-')
			i--;
		str++;
	}
	return (num);
}

void	malloc_rooms(int ***rooms, int count)
{
	if (count == 1)
	{
		(*rooms) = (int **)ft_memalloc(sizeof(int*) * count);
		while (count-- > 0)
		{
			(*rooms)[count] = (int *)ft_memalloc(sizeof(int) * 6);
			(*rooms)[count][0] = 0;
			(*rooms)[count][1] = 0;
			(*rooms)[count][2] = 0;
			(*rooms)[count][3] = -1;
			(*rooms)[count][4] = 0;
			(*rooms)[count][5] = 0;
		}
	}
	else
	{
		(*rooms) = ft_dbrealloc((*rooms), count, 5);
		(*rooms)[count - 1][3] = -1;
	}
}

void	malloc_tubes(t_lemin *lemin, int count)
{
	int		rooms;
	int		rooms_cpy;

	rooms = count;
	rooms_cpy = rooms;
	lemin->tubes = ft_memalloc(sizeof(int *) * count);
	while (--count >= 0)
	{
		rooms = rooms_cpy;
		lemin->tubes[count] = ft_memalloc(sizeof(int) * rooms_cpy);
		while (--rooms >= 0)
			lemin->tubes[count][rooms] = -1;
	}
}
