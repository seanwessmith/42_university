/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:35:06 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/09 22:30:13 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Writes a character to the standard output
*/

void	ft_putchar(char c)
{
	unsigned char	ch;

	ch = c;
	write(1, &ch, 1);
}
