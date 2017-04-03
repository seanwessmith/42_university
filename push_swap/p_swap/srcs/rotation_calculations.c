/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 07:12:33 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/01 22:15:52 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	minmax(t_stack *x)
{
	int		i;

	i = x->l + 1;
	x->max = x->s[i];
	while (--i >= 0)
		if (x->max < x->s[i])
			x->max = x->s[i];
	i = x->l;
	x->min = x->s[i];
	while (--i >= 0)
		if (x->min > x->s[i] && x->s[i] != -1)
			x->min = x->s[i];
}

int		calc_rotval_atob(t_stack *d, int nbr, int *rotate)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	minmax(d);
	if (nbr > d->max || nbr < d->min)
	{
		while (d->s[i] != d->max)
			i++;
		while (d->s[d->l - j] != d->max)
			j++;
		i += 2;
	}
	else
	{
		while (!(nbr > d->s[i] && nbr < d->s[i + 1]) && i < d->l)
			i++;
		i += 2;
		while ((!(nbr < d->s[d->l - j] && nbr > d->s[d->l - j - 1])
					&& !(nbr > d->s[d->l] && nbr < d->s[0])) && j < d->l)
			j++;
	}
	*rotate = (ft_absvalue(i) < ft_absvalue(++j)) ? 1 : 2;
	return (*rotate == 1) ? ft_absvalue(i) : ft_absvalue(j);
}

int		calc_rotval_btoa(t_stack *d, int nbr, int *rotate)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	minmax(d);
	if (nbr > d->max || nbr < d->min)
	{
		while (d->s[i] != d->min)
			i++;
		while (d->s[d->l - j] != d->min)
			j++;
		i += 2;
	}
	else
	{
		while (!(nbr < d->s[i] && nbr > d->s[i - 1]) && i < d->l)
			i++;
		i += 2;
		while ((!(nbr < d->s[d->l - j] && nbr > d->s[d->l - j - 1])
					&& !(nbr < d->s[d->l] && nbr > d->s[0])) && j < d->l)
			j++;
	}
	*rotate = (ft_absvalue(i) < ft_absvalue(++j)) ? 1 : 2;
	return (*rotate == 1) ? ft_absvalue(i) : ft_absvalue(j);
}

int		calc_rot_atob(t_stack *x, int nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	minmax(x);
	if (nbr > x->max || nbr < x->min)
	{
		while (x->s[i] != x->min)
			i++;
		while (x->s[x->l - j] != x->min)
			j++;
		i += 2;
	}
	else
	{
		while (!(nbr > x->s[i] && nbr < x->s[i + 1]) && i < x->l)
			i++;
		i += 2;
		while ((!(nbr > x->s[x->l - j] && nbr < x->s[x->l - j + 1])
					&& !(nbr > x->s[x->l] && nbr < x->s[0])) && j < x->l)
			j++;
	}
	return (i < j) ? 1 : 0;
}

int		calc_rot_btoa(t_stack *x, int nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	minmax(x);
	if (nbr > x->max || nbr < x->min)
	{
		while (x->s[i] != x->min)
			i++;
		while (x->s[x->l - j] != x->min)
			j++;
		i += 2;
	}
	else
	{
		while (!(nbr < x->s[i] && nbr > x->s[i + 1]) && i < x->l)
			i++;
		i += 2;
		while ((!(nbr > x->s[x->l - j] && nbr < x->s[x->l - j - 1])
					&& !(nbr < x->s[x->l] && nbr > x->s[0])) && j < x->l)
			j++;
	}
	return (i < j) ? 1 : 0;
}
