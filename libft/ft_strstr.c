/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 22:07:48 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/12 17:33:06 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is
 * not part of str1.
*/

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		x;

	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0')
		return (NULL);
	i = 0;
	x = 0;
	while (big[i])
	{
		while (little[x] == big[i] && little[x] && big[i])
		{
			x++;
			i++;
		}
		if (little[x] == '\0')
			return (x == 0 ? (char *)big : (char *)&big[i - x]);
		if (little[x] != big[i])
		{
			i -= x - 1;
			x = 0;
		}
	}
	return (NULL);
}
