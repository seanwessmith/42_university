/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:49:04 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/02 22:52:56 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Applies the function f to each character of the string passed as argument, and passing
 * its index as first argument. Each character is passed by address to f to be modified if
 * necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (*s != '\0')
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
