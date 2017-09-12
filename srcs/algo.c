/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 05:17:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/12 04:19:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		is_side_by_side(t_fill *e)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++x < e->x)
	{
		while (++y < e->y)
		{
			if (y < e->y - 1 && (e->tab[x][y] == e->player || e->tab[x][y] == e->player + 32) && (e->tab[x][y + 1] == e->adv || e->tab[x][y + 1] == e->adv + 32))
				e->sbs = 1;
			else if (y > 0 && (e->tab[x][y] == e->player || e->tab[x][y] == e->player + 32) && (e->tab[x][y - 1] == e->adv || e->tab[x][y - 1] == e->adv + 32))
				e->sbs = 1;
			else if (x < e->x - 1 && (e->tab[x][y] == e->player || e->tab[x][y] == e->player + 32) && (e->tab[x + 1][y] == e->adv || e->tab[x + 1][y] == e->adv + 32))
				e->sbs = 1;
			else if (x > 0 && (e->tab[x][y] == e->player || e->tab[x][y] == e->player + 32) && (e->tab[x - 1][y] == e->adv || e->tab[x - 1][y] == e->adv + 32))
				e->sbs = 1;
			if (e->sbs == 1)
				return (1);
		}
		y = -1;
	}
	return (0);
}

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
			if (e->piece[xp][yp] == '*' && (e->tab[x + xp][y + yp] == e->adv || e->tab[x + xp][y + yp] == e->adv + 32))
				return (0);
			if (e->piece[xp][yp] == '*' && (e->tab[x + xp][y + yp] == e->player || e->tab[x + xp][y + yp] == e->player + 32))
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
	e->range = 1000;
	while (++x < e->x)
	{
		while (++y < e->y)
			if (check_placement(e, x, y))
				check_range(e, x, y);
		y = -1;
	}
}

int				get_left_border(t_fill *e, const int xt, const int yt)
{
	int		x;
	int		y;

	x = e->save_px;
	y = e->save_py;
	while (y > 0)
	{
		if (e->tab[x][y] == e->adv)
			return (0);
		y--;
	}
	e->save_x = xt;
	e->save_y = yt;
	return (1);
}

int				get_right_border(t_fill *e, const int xt, const int yt)
{
	int		x;
	int		y;

	x = e->save_px;
	y = e->save_py;
	while (y > e->y)
	{
		if (e->tab[x][y] == e->adv)
			return (0);
		y++;
	}
	e->save_x = xt;
	e->save_y = yt;
	return (1);
}

void			get_border(t_fill *e)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++x < e->x)
	{
		if (e->tab[x][0] == e->player || e->tab[x][0] == e->player + 32)
			e->lborder = 1;
		while (++y < e->y)
			if (check_placement(e, x, y))
				if (!e->lborder && get_left_border(e, x , y))
					return ;
		y = -1;
	}
	x = -1;
	y = -1;
	while (++x < e->x)
	{
		if (e->tab[x][e->x] == e->player || e->tab[x][e->x] == e->player + 32)
			e->rborder = 1;
		while (++y < e->y)
			if (check_placement(e, x, y))
				if (!e->rborder && get_right_border(e, x, y))
					return ;
		y = -1;
	}
}

void		auto_fill(t_fill *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < e->x)
	{
		while (y < e->y)
		{
			if (check_placement(e, x, y))
			{
				e->save_x = x;
				e->save_y = y;
				return ;
			}
			y++;
		}
		x++;
		y = 0;
	}
	ft_printf("0 0\n");
	exit (0);
}

void			algo(t_fill *e)
{
//	sleep(1);
	if (e->sbs == 0 && !(is_side_by_side(e)))
		range(e);
	else if (!e->lborder && !e->rborder)
		get_border(e);
	else
		auto_fill(e);
	e->xp = 0;
	e->yp = 0;
	e->valid = 0;
	e->len_p = 0;
	ft_printf("%d %d\n", e->save_x, e->save_y);
	e->save_x = 0;
	e->save_y = 0;
}
