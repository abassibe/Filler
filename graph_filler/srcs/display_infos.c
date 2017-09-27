/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 01:37:38 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/27 06:11:25 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		draw_img_infos(t_fill *e, const int x, const int y, const int color)
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

static void		draw_grid(t_fill *e)
{
	int		i;

	i = 0;
	while (i < 500)
	{
		mlx_string_put(e->mlx, e->win2, i, 90, 0xffffff, "_");
		i += 15;
	}
	i = 90;
	while (i < 130)
	{
		mlx_string_put(e->mlx, e->win2, 245, i, 0xffffff, "|");
		i += 10;
	}
}

static void		fill_white(t_fill *e)
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

static void		draw_grid_infos(t_fill *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 1500)
	{
		while (x < 1500)
		{
			if (x % 10 == 0 && x > 0)
				draw_img_infos(e, y, x, 0x000000);
			if (y % 10 == 0 && y > 0)
				draw_img_infos(e, y, x, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}

static void		draw_piece2(t_fill *e, int xt, int yt, const int color2)
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
				draw_img_infos(e, y, x, color2);
			else
				draw_img_infos(e, y, x, e->color);
			x++;
		}
		x = xt + 1;
		y++;
	}
}

static void		draw_piece_infos(t_fill *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < e->xp)
	{
		while (y < e->yp)
		{
			if (e->piece[x][y] == '*')
			{
				e->color = 0xFF0000;
				draw_piece2(e, x * 10, y * 10, 0xFF7777);
			}
			y++;
		}
		y = 0;
		x++;
	}
}

static void		next_piece(t_fill *e)
{
	fill_white(e);
	draw_grid_infos(e);
	draw_piece_infos(e);
}

void			display_infos(t_fill *e)
{
	void	*xpm_img;
	int		h;
	int		w;
	int		pos;

	mlx_clear_window(e->mlx, e->win2);
	draw_grid(e);
	xpm_img = mlx_xpm_file_to_image(e->mlx, "srcs/versus.xpm", &h, &w);
	mlx_put_image_to_window(e->mlx, e->win2, xpm_img, 178, 15);
	mlx_string_put(e->mlx, e->win2, 30, 50, 0xffffff, "abassibe.filler");
	mlx_string_put(e->mlx, e->win2, 320, 50, 0xffffff, "guest.filler");
	mlx_string_put(e->mlx, e->win2, 205, 150, 0xffffff, "My Piece :");
	mlx_string_put(e->mlx, e->win2, 125, 110, 0xffffff, ft_itoa(e->m_point));
	mlx_string_put(e->mlx, e->win2, 375, 110, 0xffffff, ft_itoa(e->a_point));
	next_piece(e);
	pos = 250 - ((e->yp / 2) * 10);
	mlx_put_image_to_window(e->mlx, e->win2, e->vimg2, pos, 200);
	mlx_do_sync(e->mlx);
}
