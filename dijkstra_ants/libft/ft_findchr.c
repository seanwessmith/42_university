/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:09:18 by ssmith            #+#    #+#             */
/*   Updated: 2017/03/24 14:46:03 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_findchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == '\0')
		return (0);
	return (1);
}