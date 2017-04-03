/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 07:07:43 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/05 21:03:41 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	ss(t_stack *a, t_stack *b, int ab)
{
	s(a, b, ab);
	s(b, a, ab);
}

void	s(t_stack *a, t_stack *b, int ab)
{
	int		temp;

	if (b)
		;
	if (a->l >= 1)
	{
		temp = a->s[a->l];
		a->s[a->l] = a->s[a->l - 1];
		a->s[a->l - 1] = temp;
	}
	if (ab == 1)
		ft_printf("sa\n");
	else if (ab == 2)
		ft_printf("sb\n");
}
