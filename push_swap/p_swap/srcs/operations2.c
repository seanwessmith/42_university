/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 07:07:43 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/06 16:03:49 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	pre_s(t_stack s, t_stack d, int ab)
{
	if (ab == 1)
	{
		move_stdout(s.l + 2);
		ft_printf(GREEN"\r     %3d", s.s[s.l]);
		ft_printf(RESET"          %3d\n", d.s[d.l]);
		move_stdout(s.l + 1);
		ft_printf(GREEN"\r     %3d", s.s[s.l - 1]);
		ft_printf(RESET"          %3d\n", d.s[d.l - 1]);
	}
	else
	{
		move_stdout(s.l + 2);
		ft_printf(RESET"\r     %3d", s.s[s.l]);
		ft_printf(GREEN"          %3d\n", d.s[d.l]);
		move_stdout(s.l + 1);
		ft_printf(RESET"\r     %3d", s.s[s.l - 1]);
		ft_printf(GREEN"          %3d\n", d.s[d.l - 1]);
	}
	fflush(stdout);
}

void	s(t_stack *s, t_stack *d, int ab)
{
	int		temp;

	if (s->print > 0)
		pre_s(*s, *d, ab);
	if (s->l >= 1)
	{
		temp = s->s[s->l];
		s->s[s->l] = s->s[s->l - 1];
		s->s[s->l - 1] = temp;
	}
	if (s->print > 0)
		ps_stacks(*s, *d, 1);
	s->operations++;
	if (ab == 1 && s->print == 0)
		write(1, "sa\n", 3);
	else if (ab == 2 && s->print == 0)
		write(1, "sb\n", 3);
}

void	ps_stacks(t_stack a, t_stack b, int start)
{
	int		i;

	i = -1;
	while (i++ < a.tot_l)
	{
		move_stdout(start + i + 1);
		ft_printf(RESET"\r     %3d          %3d\n", a.s[i], b.s[i]);
	}
	fflush(stdout);
}
