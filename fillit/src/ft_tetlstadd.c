/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetlstadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 00:23:34 by vtam              #+#    #+#             */
/*   Updated: 2016/12/03 17:02:59 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tetlstadd(t_tetris **alst, t_tetris *new_ttmo)
{
	t_tetris *current;

	if (!new_ttmo)
		return ;
	if (!*alst)
		*alst = new_ttmo;
	else
	{
		current = *alst;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_ttmo;
	}
}
