/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:50:28 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 12:05:17 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

int		parse_args(char *line, t_stack *a, t_stack *b)
{
	if (ft_strequ(line, "sa"))
		s(a, b, 5);
	else if (ft_strequ(line, "sb"))
		s(b, a, 5);
	else if (ft_strequ(line, "ss"))
		ss(a, b, 5);
	else if (ft_strequ(line, "pa"))
		p(a, b, 5);
	else if (ft_strequ(line, "pb"))
		p(b, a, 5);
	else if (ft_strequ(line, "ra"))
		r(a, b, 5);
	else if (ft_strequ(line, "rb"))
		r(b, a, 5);
	else if (ft_strequ(line, "rr"))
		rx(a, b, 5);
	else if (ft_strequ(line, "rra"))
		rr(a, b, 5);
	else if (ft_strequ(line, "rrb"))
		rr(b, a, 5);
	else if (ft_strequ(line, "rrr"))
		rrr(a, b, 5);
	else
		return (-1);
	return (0);
}

int		duplicates(t_stack a)
{
	int		x;
	int		y;

	x = a.l;
	while (x >= 0)
	{
		y = a.l;
		while (y > 0)
		{
			if (a.s[x] == a.s[y] && x != y)
				return (-1);
			y--;
		}
		x--;
	}
	return (0);
}

int		readfile(t_stack a, t_stack b)
{
	int		error;
	char	*line;

	error = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (parse_args(line, &a, &b) == -1)
			return (-1);
		free(line);
	}
	if (verify(&a, 1) == 1 && duplicates(a) == 0 && error == 0)
		ft_printf("OK\n");
	else if (verify(&a, 1) == 0 && duplicates(a) == 0 && error == 0)
		ft_printf("KO\n");
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = 1;
	if (ac >= 2)
	{
		init(ac, &a, &b);
		if (parse_arr(ac, av, &a) == -1 || duplicates(a) == -1)
			ft_printf("Error\n");
		else if (readfile(a, b) == -1)
			ft_printf("Error\n");
		free(a.s);
		free(b.s);
		free(a.c);
		free(b.c);
	}
	return (0);
}
