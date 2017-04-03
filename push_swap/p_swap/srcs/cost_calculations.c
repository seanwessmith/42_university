/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 07:12:41 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/06 12:55:15 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	findcost_atob_sub(t_stack *s, t_stack *d, int i, int rotate)
{
	s->c[i] = calc_rotval_atob(d, s->s[i], &rotate);
	if (rotate == 2)
		s->c[i] = (s->l - i > s->c[i]) ? s->l - i + 1 : s->c[i]++;
	else
		s->c[i] += s->l - i + 1;
}

void	findcost_atob(t_stack *s, t_stack *d)
{
	int		i;
	int		rotate;

	rotate = 0;
	i = s->l;
	s->min_cost = -1;
	init_cost(s);
	init_cost(d);
	while (i >= 0)
	{
		if (i < s->l - i)
		{
			s->c[i] = calc_rotval_atob(d, s->s[i], &rotate);
			if (rotate == 1)
				s->c[i] = (i > s->c[i]) ? i + 1 : s->c[i]++;
			else
				s->c[i] += i + 1;
		}
		else
			findcost_atob_sub(s, d, i, rotate);
		if (s->min_cost == -1 || s->min_cost > s->c[i])
			s->min_cost = s->c[i];
		i--;
	}
}

void	findcost_btoa_sub(t_stack *s, t_stack *d, int i, int rotate)
{
	s->c[i] = calc_rotval_btoa(d, s->s[i], &rotate);
	if (rotate == 2)
		s->c[i] = (s->l - i > s->c[i]) ? s->l - i + 1 : s->c[i]++;
	else
		s->c[i] += s->l - i + 1;
}

void	findcost_btoa(t_stack *s, t_stack *d)
{
	int		i;
	int		rotate;

	rotate = 0;
	i = s->l;
	s->min_cost = -1;
	init_cost(s);
	init_cost(d);
	while (i >= 0)
	{
		if (i < s->l - i)
		{
			s->c[i] = calc_rotval_btoa(d, s->s[i], &rotate);
			if (rotate == 2)
				s->c[i] = (i > s->c[i]) ? i + 1 : s->c[i]++;
			else
				s->c[i] += i + 1;
		}
		else
			findcost_btoa_sub(s, d, i, rotate);
		if (s->min_cost == -1 || s->min_cost > s->c[i])
			s->min_cost = s->c[i];
		i--;
	}
}

int		distance(t_stack *x, int nbr)
{
	if (ft_absvalue(nbr - x->min) < ft_absvalue(nbr - x->max))
		return (ft_absvalue(nbr - x->min));
	else
		return (ft_absvalue(nbr - x->max));
}
