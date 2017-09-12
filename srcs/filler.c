/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 00:38:10 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/12 04:18:59 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/filler.h"

void			ft_error(char *error, int k)
{
	if (k == 1)
		ft_printf("%s\n", error);
	else
		perror(error);
	exit(1);
}

static t_fill	*set_struct(void)
{
	t_fill	*e;

	if (!(e = (t_fill *)malloc(sizeof(t_fill))))
		ft_error("error malloc", 1);
	e->player = 0;
	e->adv = 0;
	e->x = 0;
	e->y = 0;
	e->xp = 0;
	e->yp = 0;
	e->tab = NULL;
	e->piece = NULL;
	e->len_p = 0;
	e->valid = 0;
	e->range = 10000;
	e->sbs = 0;
	e->save_x = 0;
	e->save_y = 0;
	e->save_px = 0;
	e->save_py = 0;
	e->lborder = 0;
	e->rborder = 0;
	return (e);
}

int				main()
{
	t_fill	*e;
	char	*str;

	e = set_struct();
	e->fd = open("../tst", O_RDWR, O_CREAT);
	while (get_next_line(0, &str))
	{
		get_infos(e, str);
		if (e->player && e->x && e->y)
		{
			if (str[0] >= '0' && str[0] <= '9')
				fill_tab(e, str);
			get_x_piece(e, str);
			get_y_piece(e, str);
			if (!e->piece)
				crea_piece(e);
			fill_piece(e, str);
			if (e->valid == 1)
				algo(e);
		}
	}
}
