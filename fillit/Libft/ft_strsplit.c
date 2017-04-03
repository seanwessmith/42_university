/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:36:11 by vtam              #+#    #+#             */
/*   Updated: 2016/11/04 22:26:15 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s ||
		!(array = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (s[i] && s[j])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (s[i] == '\0' && s[j] == '\0')
			break ;
		str = ft_strsub(s, i, (j - i));
		*array++ = str;
		i = j;
	}
	*array = NULL;
	return (array - ft_wordcount(s, c));
}
