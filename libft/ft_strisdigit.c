/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:56:31 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/13 22:05:58 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strisdigit() function shall test whether all characters in the string are of class
 * digit
*/

int		ft_strisdigit(char *str)
{
	while (*str != '\0')
	{
		if (*str <= 48 && *str >= 57)
			return (0);
		str++;
	}
	return (0);
}
