/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:34:25 by vtam              #+#    #+#             */
/*   Updated: 2016/10/29 00:43:14 by vtam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
	{
		return (0);
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = ft_strnew(i + j);
	if (!str)
	{
		return (0);
	}
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
