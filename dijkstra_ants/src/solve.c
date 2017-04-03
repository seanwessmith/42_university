/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:13:49 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/24 14:22:23 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int		find_ant(t_lemin *lemin)
{
	int		i;
	int		min_ant;

	i = -1;
	min_ant = -1;
	while (++i < lemin->ant_count)
		if (lemin->ants[i][2] == 0 && min_ant != -1
				&& lemin->ants[i][0] != lemin->end)
			min_ant = (lemin->ants[i][1] <
					lemin->ants[min_ant][1]) ? i : min_ant;
		else if (lemin->ants[i][2] == 0 && min_ant == -1
				&& lemin->ants[i][0] != lemin->end)
			min_ant = i;
	return (min_ant);
}

int		find_room(t_lemin *lemin, int min_ant)
{
	int		i;
	int		min_room;
	int		cur_room;

	i = -1;
	min_room = -1;
	cur_room = lemin->ants[min_ant][0];
	while (lemin->tubes[cur_room][++i] != -1)
	{
		if (lemin->rooms[lemin->tubes[cur_room][i]][3] != -1)
		{
			if (lemin->tubes[cur_room][i] == lemin->end)
				min_room = lemin->tubes[cur_room][i];
			else if (lemin->rooms[lemin->tubes[cur_room][i]][4] == 0
					&& min_room != -1)
				min_room = (lemin->rooms[lemin->tubes[cur_room][i]][3]
						< lemin->rooms[min_room][3]) ?
					lemin->tubes[cur_room][i] : min_room;
			else if (lemin->rooms[lemin->tubes[cur_room][i]][4] == 0
					&& min_room == -1)
				min_room = lemin->tubes[cur_room][i];
		}
	}
	return (min_room);
}

void    print_ant(t_lemin *lemin, int min_ant, int min_room)
{
	if (lemin->print_colors && min_ant % 2 == 0)
		ft_printf("\x1B[%dm", min_ant % 7 + 31);
    else if (lemin->print_colors)
        ft_printf("\x1B[%dm", min_ant % 7 + 90);
    ft_printf("L%d-%d ", min_ant + 1, lemin->rooms[min_room][0]);
    if (lemin->print_colors)
        ft_printf("%s", RESET);
}

int		move_ants(t_lemin *lemin)
{
	int		min_ant;
	int		min_room;

	min_ant = find_ant(lemin);
	if (min_ant == -1)
		return (0);
	min_room = find_room(lemin, min_ant);
	if (min_room == -1)
		return (0);
	if (lemin->rooms[min_room][4] == 0 || min_room == lemin->end)
	{
        print_ant(lemin, min_ant, min_room);
		lemin->ants[min_ant][0] = min_room;
		lemin->ants[min_ant][1] = lemin->rooms[min_room][4];
		lemin->ants[min_ant][2] = 1;
		lemin->rooms[min_room][4] = 1;
		lemin->rooms[min_room][5]++;
		lemin->moves++;
		if (min_room == lemin->end)
			lemin->finished++;
		if (lemin->finished < lemin->ant_count)
			return (1);
	}
	return (0);
}

void	room_costs(t_lemin *lemin)
{
	int		i;
	int		j;

	i = 0;
	while (i < lemin->r_ct)
	{
		j = 0;
		while (lemin->tubes[i][j] != -1 && lemin->rooms[i][3] != -1)
		{
			if ((lemin->rooms[lemin->tubes[i][j]][3] == -1) ||
					(lemin->rooms[lemin->tubes[i][j]][3]
					> lemin->rooms[i][3] + 1))
			{
				lemin->rooms[lemin->tubes[i][j]][3] = lemin->rooms[i][3] + 1;
				i = 0;
			}
			j++;
		}
		i++;
	}
}

int		solve(t_lemin *lemin)
{
	int		i;

	room_costs(lemin);
	if (lemin->rooms[lemin->start][3] == -1)
		return (-1);
	i = -1;
	while (lemin->finished < lemin->ant_count)
	{
		while (move_ants(lemin) == 1)
			;
		i = -1;
		while (++i < lemin->ant_count)
			lemin->ants[i][2] = 0;
		i = -1;
		while (++i < lemin->r_ct)
			lemin->rooms[i][4] = 0;
		ft_printf("\n");
	}
	return (0);
}
