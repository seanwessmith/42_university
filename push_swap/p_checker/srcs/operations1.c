/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:50:38 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/05 21:02:56 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	p(t_stack *dst, t_stack *src, int ab)
{
	if (src->l >= 0)
	{
		dst->s[++dst->l] = src->s[src->l--];
		src->s[src->l + 1] = -1;
	}
	if (ab == 1)
		ft_printf("pa\n");
	else if (ab == 2)
		ft_printf("pb\n");
}

void	rx(t_stack *a, t_stack *b, int ab)
{
	r(a, b, 3);
	r(b, a, 3);
	if (ab == 1 || ab == 2)
		ft_printf("rr\n");
}

void	r(t_stack *a, t_stack *b, int ab)
{
	int		i;
	int		temp;
	int		temp_cost;

	if (b)
		;
	i = a->l + 1;
	temp = a->s[a->l];
	temp_cost = a->c[a->l];
	while (--i >= 1)
	{
		a->s[i] = a->s[i - 1];
		a->c[i] = a->c[i - 1];
	}
	a->s[0] = temp;
	a->c[0] = temp_cost;
	if (ab == 1)
		ft_printf("ra\n");
	else if (ab == 2)
		ft_printf("rb\n");
}

void	rrr(t_stack *a, t_stack *b, int ab)
{
	rr(a, b, 3);
	rr(b, a, 3);
	if (ab == 1 || ab == 2)
		ft_printf("rrr\n");
}

void	rr(t_stack *a, t_stack *b, int ab)
{
	int		i;
	int		temp;
	int		temp_cost;

	if (b)
		;
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
	if (ab == 1)
		ft_printf("rra\n");
	else if (ab == 2)
		ft_printf("rrb\n");
}
