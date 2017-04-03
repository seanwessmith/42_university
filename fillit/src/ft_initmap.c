/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:50:52 by ssmith            #+#    #+#             */
/*   Updated: 2016/12/03 20:50:57 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_initmap(int x)
{
	int		i;
	int		j;
	char	**box;

	i = 0;
	box = (char **)malloc(sizeof(char *) * x + 1);
	while (i < x)
	{
		j = -1;
		box[i] = (char *)malloc(sizeof(char) * x);
		while (++j < x)
			box[i][j] = '.';
		box[i][j] = '\0';
		i++;
	}
	box[i] = NULL;
	return (box);
}
