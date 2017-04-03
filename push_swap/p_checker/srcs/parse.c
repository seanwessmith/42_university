/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:50:48 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/06 16:37:14 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

int		verify(t_stack *x, int ab)
{
	int		i;

	i = -1;
	while (++i < x->l)
	{
		if (x->s[i] <= x->s[i + 1] && ab == 1)
			return (0);
		if (x->s[i] >= x->s[i + 1] && ab == 2)
			return (0);
	}
	return (1);
}

int		parse_arr(int ac, char **av, t_stack *a)
{
	ac -= 2;
	while (++a->l <= ac)
	{
		if (ft_strisdigit(av[a->l + 1], 1) == 0)
			return (-1);
		a->s[ac - a->l] = ft_atoi(av[a->l + 1]);
		if ((a->s[ac - a->l] == 0 && !ft_strequ(av[a->l + 1], "0")) ||
			(a->s[ac - a->l] == -1 && !ft_strequ(av[a->l + 1], "-1")))
			return (-1);
	}
	a->l--;
	return (0);
}

void	init(int ac, t_stack *a, t_stack *b)
{
	a->s = (int *)malloc(sizeof(int) * ac - 1);
	b->s = (int *)malloc(sizeof(int) * ac - 1);
	a->c = (int *)malloc(sizeof(int) * ac - 1);
	b->c = (int *)malloc(sizeof(int) * ac - 1);
	while (ac > 0)
	{
		a->s[ac - 1] = -1;
		b->s[ac - 1] = -1;
		a->c[ac - 1] = -1;
		b->c[ac - 1] = -1;
		ac--;
	}
	a->l = -1;
	b->l = -1;
	a->max = 0;
	b->max = 0;
	a->min_cost = -1;
	b->min_cost = -1;
}
