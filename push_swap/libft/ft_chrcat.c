/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:20:55 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/04 14:21:08 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_chrcat(char *s1, const char c)
{
	int		i;

	i = 0;
	if ((!c) || !s1)
		return (s1);
	while (s1[i] != '\0')
		i++;
	s1[i] = c;
	s1[++i] = '\0';
	return (s1);
}
