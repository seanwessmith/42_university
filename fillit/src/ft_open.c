/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:24:12 by vtam              #+#    #+#             */
/*   Updated: 2016/12/03 21:12:19 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** converts bytes read into buf as a string to 2d array
*/

char	**ft_convert(char *str)
{
	char	**ttmo2d;
	int		r;
	int		c;
	int		i;

	ttmo2d = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	r = 0;
	c = 0;
	while (r < 4)
	{
		ttmo2d[r] = (char *)malloc(sizeof(char) * 4);
		c = 0;
		while (c < 4)
		{
			ttmo2d[r][c] = str[i];
			c++;
			i++;
		}
		i++;
		r++;
	}
	return (ttmo2d);
}

void	ft_printtet(char **tet)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tet[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
** verifies the 2d array to ensure that tetrimino is valid
** checks for 4 connected hashes and all characters are '#' or '.'
*/

int		ft_verify(char **tet)
{
	int		i;
	int		j;
	int		blocks;
	int		connections;

	i = -1;
	blocks = 0;
	connections = 0;
	while (++i < 4 && (j = -1))
		while (++j < 4)
		{
			if (!(tet[i][j] == '#' || tet[i][j] == '.'))
				return (0);
			else if (tet[i][j] == '#')
				blocks++;
			connections += (tet[i][j] == '#' &&
					(j + 1) < 4 && tet[i][j + 1] == '#');
			connections += (tet[i][j] == '#' &&
					(j - 1) >= 0 && tet[i][j - 1] == '#');
			connections += (tet[i][j] == '#' &&
					(i + 1) < 4 && tet[i + 1][j] == '#');
			connections += (tet[i][j] == '#' &&
					(i - 1) >= 0 && tet[i - 1][j] == '#');
		}
	return ((connections == 6 || connections == 8) && blocks == 4);
}

/*
** normalizes blocks in array by shifting to the top left corner
*/

void	ft_normtet(char **tet)
{
	int		r;
	int		c;
	int		min_r;
	int		min_c;

	r = -1;
	min_r = 3;
	min_c = 3;
	while (++r < 4 && (c = -1))
		while (++c < 4)
		{
			if (tet[r][c] == '#' && r < min_r)
				min_r = r;
			if (tet[r][c] == '#' && c < min_c)
				min_c = c;
		}
	r = -1;
	while (++r < 4 && (c = -1))
		while (++c < 4)
			if (tet[r][c] == '#')
			{
				tet[r - min_r][c - min_c] = '#';
				if (!((r - min_r == r) && (c - min_c == c)))
					tet[r][c] = '.';
			}
}

/*
** opens and reads file attempts to add elements into linked list form
*/

int		ft_open(char *file, t_tetris **list, int last)
{
	int			fd;
	int			i;
	char		buf[BUFF_SIZE];
	char		**ttmo;
	char		letter;

	letter = 'A';
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (((i = read(fd, buf, BUFF_SIZE)) > 0))
		if (i == 20 || i == 21)
		{
			last = i;
			ttmo = ft_convert(buf);
			if (ft_verify(ttmo))
			{
				ft_normtet(ttmo);
				ft_tetlstadd(list, ft_tetlstnew(ttmo, letter++));
			}
			else
				return (0);
		}
	if (last != 20)
		return (0);
	return (1);
}
