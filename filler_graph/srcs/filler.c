/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 01:33:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 06:03:59 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			ft_error(char *error, int k)
{
	if (k == 1)
		ft_printf("%s\n", error);
	else
		perror(error);
	exit(0);
}

void			draw_img(t_fill *e, const int x, const int y, const int color)
{
	int		i;
	char	red;
	char	green;
	char	blue;

	blue = color >> 16;
	green = (color << 8) >> 16;
	red = (color << 16) >> 16;
	i = (x * 4) + (y * e->sl);
	e->img[i] = blue;
	e->img[i + 1] = green;
	e->img[i + 2] = red;
	e->img[i + 3] = 0;
}

static t_fill	*set_struct(void)
{
	t_fill	*e;

	if (!(e = ft_memalloc(sizeof(t_fill))))
		ft_error("error malloc", 1);
	e->tab = NULL;
	e->player = 0;
	e->adv = 0;
	e->x = 0;
	e->y = 0;
	e->sl = 0;
	e->len_p = 0;
	e->win = NULL;
	e->save_x = -1;
	e->save_y = -1;
	return (e);
}

void			set_mlx(t_fill *e)
{
	e->win = mlx_new_window(e->mlx, 1500, 990, "Filler");
	e->vimg = mlx_new_image(e->mlx, e->y * 10, e->x * 10);
	e->img = mlx_get_data_addr(e->vimg, &e->garb, &e->sl, &e->garb);
	e->vimg2 = mlx_new_image(e->mlx, 1500, 1500);
	e->img2 = mlx_get_data_addr(e->vimg2, &e->garb, &e->sl2, &e->garb);
}

int				main(void)
{
	t_fill	*e;
	char	*str;

	e = set_struct();
	e->mlx = mlx_init();
	while (get_next_line(0, &str))
	{
		get_infos(e, str);
		if (e->tab)
		{
			maj_data(e, str);
			if (!e->win)
				set_mlx(e);
			if (e->valid == 1)
			{
				algo(e);
				mlx_set(e);
			}
		}
		ft_strdel(&str);
	}
	free(e);
}
