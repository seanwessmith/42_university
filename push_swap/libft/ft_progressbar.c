/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progressbar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 10:27:41 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 11:58:58 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_progressbar(int cur, int max)
{
	ft_printf("\r%3d%% %.*s\n", max, cur, "XXXXXXXXXXXXXXXXXXX");
	ft_printf("\r%3d%% %.*s", (100 * cur) / max,
			(30 * cur) / max, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	fflush(stdout);
}
