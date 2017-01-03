/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:37:46 by ssmith            #+#    #+#             */
/*   Updated: 2016/11/10 20:56:49 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Outputs the string s to the standard output followed by a ’\n’
*/

void	ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr(s);
		write(1, "\n", 1);
	}
}
