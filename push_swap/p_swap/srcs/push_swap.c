/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:54:01 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 13:54:03 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	ft_push_to_a(t_stack *b, t_stack *a)
{
	minmax(b);
	minmax(a);
	findcost_btoa(b, a);
	rotatemin_a(b, a, b->l);
	if (b->s[b->l] > a->max || b->s[b->l] < a->min)
	{
		if (distance4(a, a->max) == 1)
			while (a->s[a->l] != a->min && a->l > 0)
				r(a, b, 1);
		else
			while (a->s[a->l] != a->min && a->l > 0)
				rr(a, b, 1);
	}
	else
	{
		if (calc_rot_btoa(a, b->s[b->l]) == 1)
			while (!(b->s[b->l] > a->s[0] && b->s[b->l]
						< a->s[a->l]) && a->l >= 1)
				rr(a, b, 1);
		else
			while (!(b->s[b->l] > a->s[0] && b->s[b->l]
						< a->s[a->l]) && a->l >= 1)
				r(a, b, 1);
	}
	p(a, b, 1);
}

void	ft_push_to_b(t_stack *a, t_stack *b)
{
	minmax(a);
	minmax(b);
	findcost_atob(a, b);
	rotatemin_b(a, b, a->l);
	if (a->s[a->l] > b->max || a->s[a->l] < b->min)
	{
		if (distance4(b, b->max) == 1)
			while (b->s[b->l] != b->max && b->l > 0)
				r(b, a, 2);
		else
			while (b->s[b->l] != b->max && b->l > 0)
				rr(b, a, 2);
	}
	else
	{
		if (calc_rot_atob(b, a->s[a->l]) == 1)
			while (!(a->s[a->l] < b->s[0] && a->s[a->l]
						> b->s[b->l]) && b->l >= 1)
				rr(b, a, 2);
		else
			while (!(a->s[a->l] < b->s[0] && a->s[a->l]
						> b->s[b->l]) && b->l >= 1)
				r(b, a, 2);
	}
	p(b, a, 2);
}

void	bubblesort(t_stack *a, t_stack *b)
{
	minmax(a);
	if (a->s[a->l] > a->s[a->l - 1] && a->s[a->l] != a->max)
		s(a, b, 1);
	else
		r(a, b, 1);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->print > 0)
		ps_stacks(*a, *b, 2);
	init_push(a, b);
	while (verify(a, 1) == 0 && a->l > 10)
		ft_push_to_b(a, b);
	while (verify(a, 1) == 0)
		bubblesort(a, b);
	minmax(b);
	while (b->s[b->l] != b->max && b->l > 0)
	{
		if (distance4(b, b->max) == 0)
			rr(b, a, 2);
		else
			r(b, a, 2);
	}
	minmax(a);
	while (b->l >= 0)
		ft_push_to_a(b, a);
	while (verify(a, 1) == 0)
	{
		if (distance4(a, a->min) == 0)
			rr(a, b, 1);
		else
			r(a, b, 1);
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = 1;
	if (ac >= 2)
	{
		a.print = ft_strequ(av[1], "-v") ? 1 : 0;
		a.print = ft_strequ(av[1], "-c") ? 2 : a.print;
		b.print = a.print;
		a.print > 0 ? ac-- : ac;
		init_av(av[1 + a.print], &a, &b);
		if (parse_av(av[1 + a.print], &a) == -1)
			write(1, "Error\n", 6);
		minmax(&a);
		if (a.l > 1)
			sort(&a, &b);
	}
	return (0);
}
