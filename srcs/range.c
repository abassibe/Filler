/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 06:20:08 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 04:39:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		range1(t_fill *e, const int xt, const int yt, int tmp)
{
	int		x;
	int		y;

	x = e->save_px;
	y = e->save_py;
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
}

static void		range2(t_fill *e, const int xt, const int yt, int tmp)
{
	int		x;
	int		y;

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

void			check_range(t_fill *e, const int xt, const int yt)
{
	int		tmp;

	tmp = 0;
	range1(e, xt, yt, tmp);
	tmp = 0;
	range2(e, xt, yt, tmp);
}
