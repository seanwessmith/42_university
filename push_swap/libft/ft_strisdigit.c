/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:56:31 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/01 08:48:07 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_strisdigit(char *str, int whitespace)
{
	while (*str != '\0' && whitespace == 0)
	{
		if (*str <= '0' && *str >= '9' && *str != '-')
			return (0);
		str++;
	}
	while (*str != '\0' && whitespace == 1)
	{
		if ((*str < '0' || *str > '9') && *str != ' ' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
