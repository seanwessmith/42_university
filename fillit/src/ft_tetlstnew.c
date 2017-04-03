/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetlstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 00:23:52 by vtam              #+#    #+#             */
/*   Updated: 2016/12/03 16:02:49 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_tetlstnew(char **ttmo, char letter)
{
	t_tetris *node;

	node = (t_tetris *)malloc(sizeof(t_tetris));
	if (!node)
		return (NULL);
	if (!ttmo)
	{
		node->ttmo = NULL;
		node->letter = '\0';
	}
	else
	{
		node->ttmo = ttmo;
		node->letter = letter;
	}
	node->next = NULL;
	return (node);
}
