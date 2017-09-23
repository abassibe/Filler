/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 05:17:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/23 04:48:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		check_placement(t_fill *e, const int x, const int y)
{
	int		xp;
	int		yp;
	int		count;

	xp = -1;
	yp = -1;
	count = 0;
	if (x + e->xp > e->x || y + e->yp > e->y)
		return (0);
	while (++xp < e->xp)
	{
		while (++yp < e->yp)
		{
			if (e->piece[xp][yp] == '*' && e->tab[x + xp][y + yp] == e->adv)
				return (0);
			if (e->piece[xp][yp] == '*' && e->tab[x + xp][y + yp] == e->player)
			{
				count++;
				e->save_px = x;
				e->save_py = y;
				if (count > 1)
					return (0);
			}
		}
		yp = -1;
	}
	if (count == 1)
		return (1);
	return (0);
}

static void		check_range(t_fill *e, const int xt, const int yt)
{
	int		x;
	int		y;
	int		tmp;

	x = e->save_px;
	y = e->save_py;
	tmp = 0;
	while (x > 0)
	{
		while (y > 0)
		{
			if (e->tab[x][y] == e->adv)
			{
				tmp = ft_abs(e->save_px - x) + ft_abs(e->save_py - y);
				if (tmp < e->range)
				{
					e->save_x = xt;
					e->save_y = yt;
					e->range = tmp;
				}
			}
			y--;
		}
		y = e->y;
		x--;
	}
	x = e->save_px;
	y = e->save_py;
	while (x < e->x)
	{
		while (y < e->y)
		{
			if (e->tab[x][y] == e->adv)
			{
				tmp = ft_abs(e->save_px - x) + ft_abs(e->save_py - y);
				if (tmp < e->range)
				{
					e->save_x = xt;
					e->save_y = yt;
					e->range = tmp;
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
}

static void		range(t_fill *e)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	e->range = 10000;
	while (++x < e->x)
	{
		while (++y < e->y)
			if (check_placement(e, x, y))
				check_range(e, x, y);
		y = -1;
	}
}
/*
static void		top_or_bot(t_fill *e)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++x < e->x)
	{
		while (++y < e->y)
		{
			if (e->tab[x][y] == e->player)
			{
				e->top_or_bot = 1;
				return ;
			}
			if (e->tab[x][y] == e->adv)
			{
				e->top_or_bot = 2;
				return ;
			}
		}
		y = -1;
	}
}

static void		get_rb_border(t_fill *e)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	if (!e->rborder)
	{
		while (++x < e->x)
		{
			while (++y < e->y)
			{
				if (check_placement(e, x, y))
				{
					e->save_x = x;
					e->save_y = y;
				}
			}
			y = -1;
		}
	}
}

static void		get_border(t_fill *e)
{
	if (e->top_or_bot == 0)
		top_or_bot(e);
	if (e->top_or_bot == 1)
		get_rb_border(e);
	else if (e->top_or_bot == 2)
		get_lt_border(e);
}
*/
void			algo(t_fill *e)
{
//	get_border(e);
	range(e);
	e->xp = 0;
	e->yp = 0;
	e->valid = 0;
	e->len_p = 0;
	ft_printf("%d %d\n", e->save_x, e->save_y);
}
