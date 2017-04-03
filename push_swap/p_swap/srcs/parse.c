/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:50:48 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 11:59:17 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

int		ft_parse_nbr(char *str, int *in_ct, int *error)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '-')
			sign = 1;
		if (ft_strisdigit(&str[i], 1) == 0)
			*error = -1;
		*in_ct = (*in_ct * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		*in_ct *= -1;
	return (i + 1);
}

int		parse_av(char *av, t_stack *a)
{
	int		ret;
	int		error;

	a->l = ft_count(av) - 1;
	ret = 0;
	error = 0;
	while (ret < (int)ft_strlen(av))
	{
		a->s[a->l] = 0;
		ret += ft_parse_nbr(av + ret, &a->s[a->l], &error);
		a->l--;
	}
	a->l = ft_count(av) - 1;
	return (error);
}

void	init_cost(t_stack *x)
{
	int		len;

	len = x->tot_l;
	while (len >= 0)
	{
		x->c[len] = -1;
		len--;
	}
}

void	init_push(t_stack *a, t_stack *b)
{
	if (a->l > 1 && verify(a, 1) == 0)
	{
		p(b, a, 2);
		if (a->l > 2)
		{
			p(b, a, 2);
			if (b->s[0] > b->s[1])
				r(b, a, 2);
		}
	}
}

void	init_av(char *av, t_stack *a, t_stack *b)
{
	a->tot_l = ft_count(av) - 1;
	b->tot_l = a->tot_l + 1;
	a->s = (int *)malloc(sizeof(int) * a->tot_l);
	b->s = (int *)malloc(sizeof(int) * a->tot_l);
	a->c = (int *)malloc(sizeof(int) * a->tot_l);
	b->c = (int *)malloc(sizeof(int) * a->tot_l);
	while (--b->tot_l >= 0)
	{
		a->s[b->tot_l] = -1;
		b->s[b->tot_l] = -1;
		a->c[b->tot_l] = -1;
		b->c[b->tot_l] = -1;
	}
	b->tot_l = a->tot_l;
	init_cost(a);
	init_cost(b);
	a->operations = 0;
	b->operations = 0;
	a->l = 0;
	b->l = -1;
	a->max = 0;
	b->max = 0;
	a->min_cost = -1;
	b->min_cost = -1;
}
