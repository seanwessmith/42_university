/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:50:38 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 11:59:59 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	p(t_stack *dst, t_stack *src, int ab)
{
	if (src->print > 0)
		visual_p(*dst, *src, ab);
	if (src->l >= 0)
	{
		dst->s[++dst->l] = src->s[src->l--];
		src->s[src->l + 1] = -1;
	}
	if (src->print > 0 && ab == 1)
		ps_stacks(*dst, *src, 1);
	else if (src->print > 0 && ab == 2)
		ps_stacks(*src, *dst, 1);
	src->operations++;
	if (ab == 1 && src->print == 0)
		write(1, "pa\n", 3);
	else if (ab == 2 && src->print == 0)
		write(1, "pb\n", 3);
}

void	rx(t_stack *a, t_stack *b, int ab)
{
	if (a->print > 0)
		visual_rx(*a, *b, ab);
	if (ab == 1)
	{
		r(a, b, 3);
		r(b, a, 4);
	}
	else
	{
		r(a, b, 4);
		r(b, a, 3);
	}
	if (a->print > 0 && ab == 1)
		ps_stacks(*a, *b, 1);
	else if (a->print > 0)
		ps_stacks(*b, *a, 1);
	if ((ab == 1 || ab == 2) && a->print == 0)
		write(1, "rr\n", 3);
}

void	r(t_stack *s, t_stack *d, int ab)
{
	int		i;
	int		temp;
	int		temp_cost;

	if (s->print > 0 && ab < 3)
		visual_r(*s, *d, ab);
	i = s->l + 1;
	temp = s->s[s->l];
	temp_cost = s->c[s->l];
	while (--i >= 1)
	{
		s->s[i] = s->s[i - 1];
		s->c[i] = s->c[i - 1];
	}
	s->s[0] = temp;
	s->c[0] = temp_cost;
	s->operations++;
	if (s->print > 0 && ab == 1)
		ps_stacks(*s, *d, 1);
	else if (s->print > 0 && ab == 2)
		ps_stacks(*d, *s, 1);
	if (ab == 1 && s->print == 0)
		write(1, "ra\n", 3);
	else if (ab == 2 && s->print == 0)
		write(1, "rb\n", 3);
}

void	rrr(t_stack *a, t_stack *b, int ab)
{
	if (a->print > 0)
		visual_rrr(*a, *b, ab);
	rr(a, b, 3);
	rr(b, a, 4);
	if (a->print > 0 && ab == 1)
		ps_stacks(*a, *b, 1);
	else if (a->print > 0)
		ps_stacks(*a, *b, 1);
	if ((ab == 1 || ab == 2) && a->print == 0)
		write(1, "rrr\n", 4);
}

void	rr(t_stack *a, t_stack *b, int ab)
{
	int		i;
	int		temp;
	int		temp_cost;

	if (a->print > 0 && ab < 3)
		visual_rr(*a, *b, ab);
	i = -1;
	temp = a->s[0];
	temp_cost = a->c[0];
	while (++i < a->l)
	{
		a->s[i] = a->s[i + 1];
		a->c[i] = a->c[i + 1];
	}
	a->s[a->l] = temp;
	a->c[a->l] = temp_cost;
	a->operations++;
	if (a->print > 0 && ab == 1)
		ps_stacks(*a, *b, 1);
	else if (a->print > 0 && ab == 2)
		ps_stacks(*b, *a, 1);
	if (ab == 1 && a->print == 0)
		write(1, "rra\n", 4);
	else if (ab == 2 && a->print == 0)
		write(1, "rrb\n", 4);
}
