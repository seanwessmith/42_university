/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:39:24 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/11 12:44:58 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Applies the function f to each character of the string passed as argument. Each
 * character is passed by address to f to be modified if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (s != NULL && *s)
			f(s++);
	}
}
