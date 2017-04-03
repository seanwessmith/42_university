/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:28:34 by vtam              #+#    #+#             */
/*   Updated: 2016/11/05 19:30:34 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] == c)
		i++;
	j = ft_strlen(s);
	while (s[j - 1] == c)
		j--;
	if (i <= j)
	{
		if ((str = (char *)malloc(sizeof(char) * (j - i) + 1)) == NULL)
			return (0);
		str = ft_strsub(s, i, (j - i));
		str[j - i] = '\0';
	}
	else
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
	}
	return (str);
}
