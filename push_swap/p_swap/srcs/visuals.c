/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:18:08 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 19:53:57 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/ft_printf.h"

void	visual_p(t_stack dst, t_stack src, int ab)
{
	move_stdout(0);
	ft_printf(YELLOW"\rPUSH\n");
	if (ab == 2)
	{
		move_stdout(src.l + 2);
		ft_printf(GREEN"\r     %3d", src.s[src.l]);
		ft_printf(RESET"          %3d\n", dst.s[src.l]);
		fflush(stdout);
	}
	else
	{
		move_stdout(src.l + 2);
		ft_printf(RESET"\r     %3d", dst.s[src.l]);
		ft_printf(GREEN"          %3d\n", src.s[src.l]);
		fflush(stdout);
	}
	usleep(500000);
}

void	visual_rx(t_stack a, t_stack b, int ab)
{
	move_stdout(0);
	ft_printf(YELLOW"\rROTATE A & B\n");
	if (ab == 1)
	{
		move_stdout(a.l + 2);
		ft_printf(CYAN"\r     %3d", a.s[a.l]);
		ft_printf(RESET"          %3d\n", b.s[a.l]);
		move_stdout(b.l + 2);
		ft_printf(RESET"\r     %3d", a.s[b.l]);
		ft_printf(CYAN"          %3d\n", b.s[b.l]);
	}
	else
	{
		move_stdout(2);
		ft_printf(CYAN"\r     %3d", b.s[a.l]);
		ft_printf(RESET"          %3d\n", a.s[a.l]);
		move_stdout(b.l + 2);
		ft_printf(RESET"\r     %3d", b.s[0]);
		ft_printf(CYAN"          %3d\n", a.s[0]);
	}
	fflush(stdout);
	usleep(500000);
}

void	visual_r(t_stack a, t_stack b, int ab)
{
	move_stdout(0);
	ft_printf(YELLOW"\rROTATE\n");
	if (ab == 1)
	{
		move_stdout(a.l + 2);
		ft_printf(CYAN"\r     %3d", a.s[a.l]);
		ft_printf(RESET"          %3d\n", b.s[a.l]);
	}
	else if (ab == 2)
	{
		move_stdout(a.l + 2);
		ft_printf(RESET"\r     %3d", b.s[a.l]);
		ft_printf(CYAN"          %3d\n", a.s[a.l]);
	}
	fflush(stdout);
	usleep(500000);
}

void	visual_rrr(t_stack a, t_stack b, int ab)
{
	move_stdout(0);
	ft_printf(YELLOW"\rREVERSE ROTATE A & B\n");
	if (ab == 1)
	{
		move_stdout(2);
		ft_printf(CYAN"\r     %3d", a.s[0]);
		ft_printf(CYAN"          %3d\n", b.s[0]);
	}
	else
	{
		move_stdout(2);
		ft_printf(CYAN"\r     %3d", b.s[0]);
		ft_printf(CYAN"          %3d\n", a.s[0]);
	}
	fflush(stdout);
	usleep(500000);
}

void	visual_rr(t_stack a, t_stack b, int ab)
{
	move_stdout(0);
	ft_printf(YELLOW"\rREVERSE ROTATE\n");
	if (ab == 1)
	{
		move_stdout(2);
		ft_printf(CYAN"\r     %3d", a.s[0]);
		ft_printf(RESET"          %3d\n", b.s[0]);
		fflush(stdout);
	}
	else if (ab == 2)
	{
		move_stdout(a.l + 2);
		ft_printf(RESET"\r     %3d", a.s[a.l]);
		ft_printf(CYAN"          %3d\n", b.s[a.l]);
		fflush(stdout);
	}
	usleep(500000);
}
