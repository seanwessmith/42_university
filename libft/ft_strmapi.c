/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:57:07 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/10 20:11:02 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Applies the function f to each character of the string passed as argument by giving its
 * index as first argument to create a “fresh” new string with malloc resulting from
 * the successive applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = NULL;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (str)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
