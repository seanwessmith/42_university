/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stdout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:13:49 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/07 13:04:14 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	move_stdout(int row)
{
	char	*str;

	str = ft_strnew(0);
	str = ft_strcat(str, "tput cup ");
	str = ft_strcat(str, ft_itoa(row));
	str = ft_strcat(str, " 0");
	system(str);
	ft_printf("%c[2K", 27);
	free(str);
}
