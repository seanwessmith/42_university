/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 09:48:30 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 12:49:06 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

int		ft_count(char *str)
{
	int		count;
	int		lst_space;

	count = (*str != ' ') ? 1 : 0;
	lst_space = (*str != ' ') ? 0 : 1;
	while (*str)
	{
		if (lst_space == 1)
		{
			count++;
			lst_space = 0;
		}
		if (*str == ' ')
			lst_space = 1;
		str++;
	}
	return (count);
}

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

int		distance4(t_stack *x, int nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (x->s[i] != nbr)
		i++;
	while (x->s[x->l - j] != nbr)
		j++;
	if (i < j)
		return (0);
	else
		return (1);
}

void	rotatemin_a(t_stack *a, t_stack *b, int i)
{
	int		temp;
	int		rotation;
	int		r_dist;

	while (a->c[i] != a->min_cost && i > 0)
		i--;
	temp = a->s[i];
	if (a->s[a->l - 1] == temp && a->c[a->l] < a->c[a->l - 2] - 2)
		s(a, b, 1);
	else if ((r_dist = calc_rotval_atob(b, temp, &rotation)))
	{
		if (i < a->l - i && rotation == 2)
			while (a->s[a->l] != temp && --r_dist > 0)
				rrr(a, b, 1);
		else if (i > a->l - i && rotation == 1)
			while (a->s[a->l] != temp && --r_dist > 0)
				rx(a, b, 1);
		if (i < a->l - i)
			while (a->s[a->l] != temp)
				rr(a, b, 1);
		else
			while (a->s[a->l] != temp)
				r(a, b, 1);
	}
}

void	rotatemin_b(t_stack *src, t_stack *dst, int i)
{
	int		temp;
	int		rotation;
	int		r_dist;

	while (src->c[i] != src->min_cost && i > 0)
		i--;
	temp = src->s[i];
	if (src->s[src->l - 1] == temp && src->c[src->l] < src->c[src->l - 2] - 2)
		s(src, dst, 1);
	else if ((r_dist = calc_rotval_atob(dst, temp, &rotation)))
	{
		if (i < src->l - i && rotation == 1)
			while (src->s[src->l] != temp && --r_dist > 0)
				rrr(src, dst, 1);
		else if (i > src->l - i && rotation == 2)
			while (src->s[src->l] != temp && r_dist-- > 0)
				rx(src, dst, 1);
		if (i < src->l - i)
			while (src->s[src->l] != temp)
				rr(src, dst, 1);
		else
			while (src->s[src->l] != temp)
				r(src, dst, 1);
	}
}
