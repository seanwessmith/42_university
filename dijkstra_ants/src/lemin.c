/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:03:36 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/24 17:36:03 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	handle_errors(int ret)
{
	if (ret == -1)
		ft_printf("Bad input\n");
	if (ret == -2)
		ft_printf("No ants\n");
	if (ret == -3)
		ft_printf("No rooms\n");
	if (ret == -4)
		ft_printf("Missing start or finish\n");
}

void	handle_flags(t_lemin lemin)
{
	ft_printf("\n");
	ft_printf(RESET BG_BLACK"");
	if (lemin.print_ants == 1)
		ft_printf(WHITE"ANT COUNT = %6d  \n", lemin.ant_count);
	ft_printf(RESET BG_BLACK"");
	if (lemin.print_moves == 1)
		ft_printf(WHITE"MOVES = %10d  \n", lemin.moves);
	ft_printf(RESET BG_BLACK"");
	if (lemin.print_rooms == 1)
	{
		while (lemin.r_ct-- > 0)
			if (lemin.rooms[lemin.r_ct][5] != 0)
				ft_printf(GREEN"Room %d used %d times\n",
						lemin.r_ct, lemin.rooms[lemin.r_ct][5]);
			else
				ft_printf(RED"Room %d used %d times\n",
						lemin.r_ct, lemin.rooms[lemin.r_ct][5]);
	}
	ft_printf(RESET BG_BLACK"");
	ft_printf("\n");
}

int		main(int ac, char **av)
{
	int			i;
	int			ret;
	t_lemin		*lemin;

	i = -1;
	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	if ((ret = parse_input(ac, av, lemin)) == 1)
	{
		if (solve(lemin) == -1)
			ft_printf("No possible solution\n");
		handle_flags(*lemin);
	}
	handle_errors(ret);
	return (0);
}
