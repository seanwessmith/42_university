/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:00:25 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/13 22:05:48 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strisprint() function shall test whether all characters in the string are printable
 * characters
*/

int		ft_strisprint(char *str)
{
	while (*str != '\0')
	{
		if (*str <= 32 && *str >= 126)
			return (0);
		str++;
	}
	return (1);
}
