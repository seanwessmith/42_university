/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 04:59:16 by ssmith            #+#    #+#             */
/*   Updated: 2017/02/27 05:21:33 by ssmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/includes/ft_printf.h"

void	draw_grid(t_fdf *fdf)
{
	long	x;
	long	y;

	x = 0;
	y = 0;
	while (x < fdf->rows)
	{
		y = 0;
		while (y < fdf->cols)
		{
			if (y < fdf->cols - 1)
				draw_line(fdf, fdf->iso[x][y], fdf->iso[x][y + 1]);
			if (x < fdf->rows - 1)
				draw_line(fdf, fdf->iso[x][y], fdf->iso[x + 1][y]);
			y++;
		}
		x++;
	}
}

void	iso_proj(t_pt *iso)
{
	int		x0;
	int		y0;

	x0 = iso->x;
	y0 = iso->y;
	iso->y = (1 / sqrt(6) * (1 * x0 - sqrt(3) * iso->z));
	iso->x = (1 / sqrt(6) * (x0 + 1 * y0 + iso->z));
	iso->z = (1 / sqrt(6) * (1 * x0 - sqrt(2) * y0 + sqrt(2) * iso->z));
}

void	reset_iso(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 0;
	while (x < fdf->rows)
	{
		y = 0;
		while (y < fdf->cols)
		{
			fdf->iso[x][y].x = x;
			fdf->iso[x][y].y = y;
			fdf->iso[x][y].z = fdf->in[x][y];
			y++;
		}
		x++;
	}
}

void	iso(t_fdf *fdf)
{
	int		x;
	int		y;

	fdf->scale = (fdf->rows > fdf->cols)
		? ((float)WIN_H / 1.5) / ((float)fdf->rows)
		: ((float)WIN_W / 1.5) / ((float)fdf->cols);
	x = 0;
	while (x < fdf->rows)
	{
		y = 0;
		while (y < fdf->cols)
		{
			fdf->iso[x][y].x *= fdf->scale;
			fdf->iso[x][y].y *= fdf->scale;
			fdf->iso[x][y].z *= fdf->scale;
			fdf->iso[x][y].x += fdf->centerx;
			fdf->iso[x][y].y += fdf->centery;
			iso_proj(&fdf->iso[x][y]);
			y++;
		}
		x++;
	}
}

int		ft_key(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(1);
	}
	if (keycode == 1)
		fdf->centerx += 50;
	else if (keycode == 13)
		fdf->centerx -= 50;
	else if (keycode == 2)
		fdf->centery += 50;
	else if (keycode == 0)
		fdf->centery -= 50;
	reset_iso(fdf);
	iso(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_grid(fdf);
	return (0);
}
