/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 02:17:38 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 01:59:52 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		fill_window(t_fill *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < e->y * 10)
	{
		while (x < e->x * 10)
		{
			if (x == 0 || y == 0)
				draw_img(e, y, x, 0xFF000000);
			else
				draw_img(e, y, x, 0xFFFFFF);
			x++;
		}
		y++;
		x = 0;
	}
}

static void		draw_grid(t_fill *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < e->y * 10)
	{
		while (x < e->x * 10)
		{
			if (x % 10 == 0 && x > 0)
				draw_img(e, y, x, 0x000000);
			if (y % 10 == 0 && y > 0)
				draw_img(e, y, x, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
	e->draw = 1;
}

static void		draw_piece(t_fill *e, int xt, int yt, const int color2)
{
	int		x;
	int		y;

	x = xt + 1;
	y = yt + 1;
	while (y < yt + 10)
	{
		while (x < xt + 10)
		{
			if (x > xt + 7 || y > yt + 7)
				draw_img(e, y, x, color2);
			else
				draw_img(e, y, x, e->color);
			x++;
		}
		x = xt + 1;
		y++;
	}
}

static void		draw_tab(t_fill *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < e->x)
	{
		while (y < e->y)
		{
			if (e->tab[x][y] == e->player)
			{
				e->color = 0xFF0000;
				draw_piece(e, x * 10, y * 10, 0xFF7777);
			}
			else if (e->tab[x][y] == e->adv)
			{
				e->color = 0x0000FF;
				draw_piece(e, x * 10, y * 10, 0x7777FF);
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void			mlx_set(t_fill *e)
{
	if (e->draw == 0)
	{
		fill_window(e);
		draw_grid(e);
	}
	draw_tab(e);
	e->save_x = 0;
	e->save_y = 0;
	mlx_do_sync(e->mlx);
}
