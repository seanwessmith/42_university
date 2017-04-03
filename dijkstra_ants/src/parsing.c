/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:01:18 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/24 18:30:21 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int		count_nums(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' &&
				(*(str + 1) == ' ' || *(str + 1) == '-' || *(str + 1) == 0))
			count++;
		str++;
	}
	return (count);
}

int		parse_rooms(char *line, t_lemin *lemin)
{
	if (count_nums(line) == 0)
		return (-1);
	if (lemin->r_ct > 0)
		malloc_rooms(&lemin->rooms, ++lemin->r_ct);
	else
		malloc_rooms(&lemin->rooms, ++lemin->r_ct);
	lemin->rooms[lemin->r_ct - 1][0] = parse_numstr(line, 0);
	lemin->rooms[lemin->r_ct - 1][1] = parse_numstr(line, 1);
	lemin->rooms[lemin->r_ct - 1][2] = parse_numstr(line, 2);
	lemin->start = (lemin->start == -1) ? lemin->r_ct - 1: lemin->start;
	if (lemin->end == -1)
	{
		lemin->end = lemin->r_ct -1;
		lemin->rooms[lemin->end][3] = 0;
	}
	return (0);
}

void	parse_tubes(char *line, t_lemin *lemin)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	if (lemin->t_ct == 0)
	{
		malloc_tubes(lemin, lemin->r_ct);
		lemin->t_ct++;
	}
	j = 0;
	while (lemin->rooms[j][0] != parse_numstr(line, 0))
		j++;
	z = 0;
	while (lemin->rooms[z][0] != parse_numstr(line, 1))
		z++;
	while (lemin->tubes[j][i] != -1)
		i++;
	lemin->tubes[j][i] = z;
	i = 0;
	j = 0;
	while (lemin->rooms[j][0] != parse_numstr(line, 1))
		j++;
	z = 0;
	while (lemin->rooms[z][0] != parse_numstr(line,0))
		z++;
	while (lemin->tubes[j][i] != -1)
		i++;
	lemin->tubes[j][i] = z;
}

void	process_flags(int ac, char **av, t_lemin *lemin)
{
	while (ac >= 1)
	{
		if (lemin->print_colors == 0)
			lemin->print_colors = ft_strequ(av[ac], "-c");
		if (lemin->print_moves == 0)
			lemin->print_moves = ft_strequ(av[ac], "-m");
		if (lemin->print_ants == 0)
			lemin->print_ants = ft_strequ(av[ac], "-a");
		if (lemin->print_rooms == 0)
			lemin->print_rooms = ft_strequ(av[ac], "-r");
		ac--;
	}
}

int		parse_input(int ac, char **av, t_lemin *lemin)
{
	char	*line;
	
	if (ac > 1)
		process_flags(ac, av, lemin);
	lemin->ant_count = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (line[0] == '#' && lemin->start != -1 && lemin->end != -1)
			parse_hash(line, lemin);
		else if (lemin->ant_count == 0)
		{
			if (ft_strisdigit(line, 1) == 0)
				return (-2);
			lemin->ant_count = ft_atoi(line);
			init_lemin(lemin, 0);
		}
		else if (count_nums(line) == 3 || lemin->start == -1 || lemin->end == -1)
		{
			if (parse_rooms(line, lemin) == -1)
				return (-4);
		}
		else if (count_nums(line) == 2)
		{
			if (!(lemin->rooms))
				return (-3);
			if (lemin->startend != 2)
				return (-4);
			parse_tubes(line, lemin);
		}
		else
			return (-1);
		ft_putendl(line);
		free(line);
	}
	ft_printf("\n");
	if (lemin->ant_count != 0)
		init_lemin(lemin, 1);
	return (lemin->ant_count != 0) ? 1 : 0;
}
