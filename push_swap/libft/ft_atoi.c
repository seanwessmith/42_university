/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:57:40 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/28 15:45:08 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_atoi(const char *str)
{
	unsigned long long	x;
	int					i;
	int					mn;

	i = 0;
	x = 0;
	mn = 1;
	while (BLANK(str[i]))
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		mn = str[i] == '-' ? -1 : 1;
		str++;
	}
	while (*str == '0')
		str++;
	while (str[i] != '\0')
	{
		if (str[i] > 57 || str[i] < 48)
			return (mn * x);
		x = x * 10 + (str[i++] - '0');
	}
	if (i > 10 || x > 2147483647)
		return (-1);
	return (mn * x);
}
