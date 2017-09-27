/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 01:33:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/27 05:57:51 by abassibe         ###   ########.fr       */
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
	t_fill	*e;

	if (!(e = ft_memalloc(sizeof(t_fill))))
		ft_error("error malloc", 1);
	return (e);
	e->tab = NULL;
	e->player = 0;
	e->adv = 0;
	e->x = 0;
	e->y = 0;
	e->len_p = 0;
	e->save_x = -1;
	e->save_y = -1;
}

int				main(void)
{
	t_fill	*e;
	char	*str;

	e = set_struct();
	while (get_next_line(0, &str))
	{
		get_infos(e, str);
		if (e->tab)
		{
			maj_data(e, str);
			if (e->valid == 1)
			{
				algo(e);
			}
		}
	}
}
