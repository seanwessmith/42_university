/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:35:43 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/09 19:41:10 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The memchr() function scans the initial n bytes of the memory area
 * pointed to by s for the first instance of c.  Both c and the bytes of
 * the memory area pointed to by s are interpreted as unsigned char.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
