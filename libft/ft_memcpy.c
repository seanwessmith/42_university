/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:30:59 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/09 16:34:29 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The memcpy() function copies n bytes from memory area src to memory
 * area dest.  The memory areas must not overlap.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (n-- > 0)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
