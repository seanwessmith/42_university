/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:02:26 by exam              #+#    #+#             */
/*   Updated: 2017/01/19 14:12:49 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	int		len;
	int		neg;
	int		v;
	char	*str;

	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value < 0)
		neg = 1;
	else
		neg = 0;
	len = 1 + neg;
	v = value;
	while (v /= base)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[0] = '-';
	str[len] = 0;
	while (len-- > neg)
	{
		if (value < 0)
			v = -(value % base);
		else
			v = value % base;
		if (v > 9)
			str[len] = v + 'A' - 10;
		else
			str[len] = v + '0';
		value /= base;
	}
	return (str);
}
