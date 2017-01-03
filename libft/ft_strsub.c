/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:19:44 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/10 20:13:35 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Allocates with malloc and returns a new substring from the string given as an
 * argument. The substring begins at index start and is of size len. If start and len
 * aren’t referring to a valid substring, the behavior is undefined. If the allocation
 * fails, the function returns NULL
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (s)
	{
		if (len > (ft_strlen(s) - start))
			return (NULL);
		str = (char *)malloc(sizeof(char) * len + 1);
		if (str)
		{
			while (s[start] && i < len)
			{
				str[i] = s[start];
				i++;
				start++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
