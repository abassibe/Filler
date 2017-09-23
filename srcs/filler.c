/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 01:33:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/23 05:16:30 by abassibe         ###   ########.fr       */
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

static t_fill	*set_struct(void)
{
	t_fill  *e;
	if (!(e = ft_memalloc(sizeof(t_fill))))
		ft_error("error malloc", 1);
	return (e);
	e->tab = NULL;
	e->player = 0;
	e->adv = 0;
	e->x = 0;
	e->y = 0;
	e->sl = 0;
	e->top_or_bot = 0;
	e->len_p = 0;
	e->win = NULL;
}

int				main()
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
			{
				dprintf(2, "TEEEEEEEEEEEEEEEEEEEEEST\n");
				e->win = mlx_new_window(e->mlx, e->y * 10, e->x * 10, "Filler");
				e->vimg = mlx_new_image(e->mlx, e->y * 10, e->x * 10);
				e->img = mlx_get_data_addr(e->vimg, &e->garb, &e->sl, &e->garb);
			}
			if (e->valid == 1)
			{
				algo(e);
				mlx_set(e);
				mlx_put_image_to_window(e->mlx, e->win, e->vimg, 0, 0);
			}
		}
	}
}
