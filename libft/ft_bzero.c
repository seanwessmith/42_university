/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:25:05 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/06 16:43:38 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The bzero() function shall place n zero-valued bytes in the area pointed to by s.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
