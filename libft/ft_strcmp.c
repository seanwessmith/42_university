/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:35:36 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/10 16:56:56 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strcmp() function compares the two strings s1 and s2. It returns an integer less
 * than, equal to, or greater than zero if s1 is found, respectively, to be less than, to
 * match, or be greater than s2
*/
int		ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	unsigned const char	*str1;
	unsigned const char *str2;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	i = 0;
	while (str1[i])
	{
		if (str1[i] < 0)
			return (str2[i] - str1[i]);
		if (str2[i] != str1[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (str2[i] != str1[i])
		return (str1[i] - str2[i]);
	return (0);
}
