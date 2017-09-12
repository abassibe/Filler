/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 03:40:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/08 03:29:13 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char		**crea_tab(const int x, const int y)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * x)))
		ft_error("error malloc", 1);
	while (i <= y)
		if (!(tab[i++] = ft_strnew(y)))
			ft_error("error malloc", 1);
	return (tab);
}

static void		get_player_id(t_fill *e, const char *str)
{
	if (ft_strcmp("$$$ exec p1 : [players/abassibe.filler]", str) == 0)
	{
		e->player = 'O';
		e->adv = 'X';
	}
	else if (ft_strcmp("$$$ exec p2 : [players/abassibe.filler]", str) == 0)
	{
		e->player = 'X';
		e->adv = 'O';
	}
}

static int		get_x(const char *str)
{
	if (ft_strncmp("Plateau ", str, 8) == 0)
		return (ft_atoi(&str[8]));
	return (0);
}

static int		get_y(const char *str)
{
	int		i;

	i = 8;
	if (ft_strncmp("Plateau ", str, 8) == 0)
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		i++;
		return (ft_atoi(&str[i]));
	}
	return (0);
}

void	get_infos(t_fill *e, const char *str)
{
	if (!e->player)
		get_player_id(e, str);
	if (!e->x)
		e->x = get_x(str);
	if (!e->y)
		e->y = get_y(str);
	if (e->x && e->y && !e->tab)
		e->tab = crea_tab(e->x, e->y);
}
