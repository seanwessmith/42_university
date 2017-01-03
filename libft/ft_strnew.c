/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:19:24 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/10 16:11:17 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Allocates (with malloc(3)) and returns a “fresh” string end- ing with ’\0’. Each
 * character of the string is initialized at ’\0’. If the allocation fails the function
 * returns NULL.
*/

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
