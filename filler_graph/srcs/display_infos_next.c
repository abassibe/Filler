/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_infos_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 03:33:39 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 06:06:49 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	fill_white(t_fill *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 1500)
	{
		while (x < 1500)
		{
			if (y < e->yp * 10 && x < e->xp * 10)
				draw_img_infos(e, y, x, 0xFFFFFF);
			else
				draw_img_infos(e, y, x, 0x000000);
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_img_infos(t_fill *e, const int x, const int y, const int color)
{
	int		i;
	char	red;
	char	green;
	char	blue;

	red = color >> 16;
	green = (color << 8) >> 16;
	blue = (color << 16) >> 16;
	i = (x * 4) + (y * e->sl2);
	e->img2[i] = red;
	e->img2[i + 1] = green;
	e->img2[i + 2] = blue;
	e->img2[i + 3] = 0;
}

void	draw_grid2(t_fill *e)
{
	int		i;

	i = 0;
	while (i < 500)
	{
		mlx_string_put(e->mlx, e->win, i, 90, 0xffffff, "_");
		i += 15;
	}
	i = 90;
	while (i < 130)
	{
		mlx_string_put(e->mlx, e->win, 245, i, 0xffffff, "|");
		i += 10;
	}
}
