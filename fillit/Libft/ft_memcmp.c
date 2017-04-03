/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 17:49:34 by vtam              #+#    #+#             */
/*   Updated: 2016/10/28 23:34:55 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char u1;
	unsigned char u2;

	while (n)
	{
		u1 = *(unsigned char *)s1;
		u2 = *(unsigned char *)s2;
		s1++;
		s2++;
		n--;
		if (u1 != u2)
		{
			return (u1 - u2);
		}
	}
	return (0);
}
