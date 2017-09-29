/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 03:40:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 05:21:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char		**crea_tab(const int x, const int y)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * x)))
		ft_error("error malloc", 1);
	while (i < x)
		if (!(tab[i++] = ft_strnew(y)))
			ft_error("eror malloc", 1);
	return (tab);
}

static void		get_player_id(t_fill *e, const char *str)
{
	if (str[10] == '1')
	{
		e->player = 'O';
		e->adv = 'X';
	}
	else if (str[10] == '2')
	{
		e->player = 'X';
		e->adv = 'O';
	}
}

static int		get_y(const char *str)
{
	int		i;

	i = 8;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	return (ft_atoi(&str[i]));
}

void			get_infos(t_fill *e, const char *str)
{
	if (!e->player && str[0] == '$')
		get_player_id(e, str);
	if (!e->x && (str[0] == 'P' && str[1] == 'l'))
		e->x = ft_atoi(&str[8]);
	if (!e->y && (str[0] == 'P' && str[1] == 'l'))
		e->y = get_y(str);
	if (e->x && e->y && !e->tab)
		e->tab = crea_tab(e->x, e->y);
}
