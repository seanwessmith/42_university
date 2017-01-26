/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwhite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 22:34:24 by ssmith            #+#    #+#             */
/*   Updated: 2017/01/22 22:40:37 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strwhite(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if ((*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n'))
			return (1);
		str++;
	}
	return (0);
}