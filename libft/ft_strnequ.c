/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:16:41 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/10 21:17:26 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Lexicographical comparison between s1 and s2 up to n char- acters or until a ’\0’ is
 * reached. If the 2 strings are identical, the function returns 1, or 0 otherwise.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && i <= n)
			i++;
		if (s1[i] == s2[i] || i == n)
			return (1);
	}
	return (0);
}
