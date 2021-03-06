/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:52:07 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/13 22:04:42 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strisalpha() function shall test whether all characters in the string are of class
 * alpha
*/

int		ft_strisalpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str <= 65 && *str >= 90) || (*str <= 97 && *str >= 122))
			return (0);
		str++;
	}
	return (1);
}
