/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:14:49 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/10 20:11:52 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Lexicographical comparison between s1 and s2. If the 2 strings are identical the
 * function returns 1, or 0 otherwise.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}
