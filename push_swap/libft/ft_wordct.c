/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:21:42 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/22 17:54:28 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_wordct(char const *str, char c)
{
	int		i;
	int		word_ct;

	i = 0;
	word_ct = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			word_ct++;
		i++;
	}
	return (word_ct);
}
