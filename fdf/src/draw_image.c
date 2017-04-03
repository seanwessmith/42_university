/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 04:58:37 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/27 05:18:48 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/includes/ft_printf.h"

int		count(int fd, char **av, t_fdf *fdf)
{
	int		i;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		fdf->cols = ft_count(line);
		fdf->rows++;
	}
	close(fd);
	return (0);
}

void	init_fdf(t_fdf *fdf)
{
	if (!fdf->rows || !fdf->cols)
	{
		fdf->rows = 0;
		fdf->cols = 0;
	}
	fdf->color = 0x00FFFFFF;
	fdf->scale = (fdf->rows > fdf->cols) ?
		((float)WIN_H / 1.5) / ((float)fdf->rows)
		: ((float)WIN_W / 1.5) / ((float)fdf->cols);
	fdf->centery = (WIN_W - ((fdf->cols) * fdf->scale)) / 2;
	fdf->centerx = (WIN_H - ((fdf->rows) * fdf->scale)) / 2;
}

void	draw_line(t_fdf *fdf, t_pt iso1, t_pt iso2)
{
	VARS;
	x0 = iso1.x;
	x1 = iso2.x;
	y0 = iso1.y;
	y1 = iso2.y;
	fdf->l.dx = ft_absvalue(x1 - x0);
	fdf->l.sx = x0 < x1 ? 1 : -1;
	fdf->l.dy = ft_absvalue(y1 - y0);
	fdf->l.sy = y0 < y1 ? 1 : -1;
	fdf->l.err = (fdf->l.dx > fdf->l.dy ? fdf->l.dx : -fdf->l.dy) / 2;
	while (!(x0 == x1 && y0 == y1))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, fdf->color);
		fdf->l.e2 = fdf->l.err;
		if (fdf->l.e2 > -fdf->l.dx)
		{
			fdf->l.err -= fdf->l.dy;
			x0 += fdf->l.sx;
		}
		if (fdf->l.e2 < fdf->l.dy)
		{
			fdf->l.err += fdf->l.dx;
			y0 += fdf->l.sy;
		}
	}
}
