/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:41:07 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/09 20:14:05 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char	*str2;

	str2 = str;
	while (len > 0)
	{
		*str2++ = c;
		len--;
	}
	return (str);
}
