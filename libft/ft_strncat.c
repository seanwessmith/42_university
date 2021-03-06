/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 21:23:36 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/07 09:31:41 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Appends the first num characters of source to destination, plus a terminating null
 * character.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	x;
	size_t	i;

	if (n != 0)
	{
		x = 0;
		i = 0;
		while (s1[i] != '\0')
			i++;
		while (s2[x] != '\0' && x < n)
		{
			s1[i + x] = s2[x];
			x++;
		}
		s1[i + x] = '\0';
	}
	return (s1);
}
