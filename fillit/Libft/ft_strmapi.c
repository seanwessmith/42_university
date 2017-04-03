/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:24:19 by vtam              #+#    #+#             */
/*   Updated: 2016/10/29 00:42:45 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	char			*str;
	unsigned int	j;

	if (s)
	{
		i = 0;
		j = 0;
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!str)
		{
			return (0);
		}
		while (*s)
		{
			str[i] = f(j, *s);
			s++;
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
