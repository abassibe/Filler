/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 05:17:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 03:31:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		check_placement(t_fill *e, const int x, const int y, int count)
{
	int		xp;
	int		yp;

	xp = -1;
	yp = -1;
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

static void		range(t_fill *e)
{
	int		x;
	int		y;
	int		count;

	x = -1;
	y = -1;
	e->range = 10000;
	while (++x < e->x)
	{
		count = 0;
		while (++y < e->y)
			if ((x + e->xp <= e->x && y + e->yp <= e->y) &&
					check_placement(e, x, y, count))
				check_range(e, x, y);
		y = -1;
	}
}

void			algo(t_fill *e)
{
	void	*xpm_font;
	int		x;
	int		y;
	int		h;
	int		w;

	y = 495 - ((e->x / 2) * 10);
	x = 510 + (495 - (e->y / 2) * 10);
	display_infos(e);
	range(e);
	e->xp = 0;
	e->yp = 0;
	e->valid = 0;
	e->len_p = 0;
	xpm_font = mlx_xpm_file_to_image(e->mlx, "srcs/font.xpm", &h, &w);
	mlx_put_image_to_window(e->mlx, e->win, xpm_font, 510, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->vimg, x, y);
	ft_printf("%d %d\n", e->save_x, e->save_y);
	e->save_x = -1;
	e->save_y = -1;
	e->m_point = 0;
	e->a_point = 0;
}
