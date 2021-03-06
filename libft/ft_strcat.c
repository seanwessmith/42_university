/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 21:26:11 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/03 14:20:06 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strcat() function appends the src string to the dest string, overwriting the
 * terminating null byte ('\0') at the end of dest, and then adds a terminating null byte
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[x] != '\0')
	{
		s1[i + x] = s2[x];
		x++;
	}
	s1[i + x] = '\0';
	return (s1);
}
