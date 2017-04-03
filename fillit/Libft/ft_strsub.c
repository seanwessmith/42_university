/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:30:01 by vtam              #+#    #+#             */
/*   Updated: 2016/10/29 00:50:40 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	if (!str)
		return (0);
	if (s)
	{
		while (*s && i < start)
			i++;
		while (*s && len > 0)
		{
			str[j] = s[i];
			j++;
			i++;
			len--;
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}
