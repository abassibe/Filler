/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 04:22:26 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 01:33:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		fill_tab(t_fill *e, const char *str)
{
	int		x;
	int		y;

	x = ft_atoi(str);
	y = -1;
	while (++y < e->y)
	{
		if (str[y + 4] == e->adv)
			e->a_point++;
		if (str[y + 4] == e->player)
			e->m_point++;
		e->tab[x][y] = str[y + 4];
	}
}

static void		crea_piece(t_fill *e)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * 150)))
		ft_error("error malloc", 1);
	while (i < 150)
		if (!(tab[i++] = ft_strnew(150)))
			ft_error("error malloc", 1);
	e->piece = tab;
}

static int		get_y_piece(const char *str)
{
	int		i;

	i = 6;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	return (ft_atoi(&str[i]));
}

static void		fill_piece(t_fill *e, const char *str)
{
	int		i;

	i = 0;
	while (i < 150)
		e->piece[e->len_p][i++] = 0;
	i = 0;
	while (str[i])
	{
		e->piece[e->len_p][i] = str[i];
		i++;
	}
	e->len_p++;
	if (e->len_p == e->xp)
		e->valid = 1;
}

void			maj_data(t_fill *e, const char *str)
{
	if (!e->piece)
		crea_piece(e);
	if (str[0] >= '0' && str[0] <= '9')
		fill_tab(e, str);
	if (str[0] == 'P' && str[1] == 'i')
	{
		e->xp = ft_atoi(&str[6]);
		e->yp = get_y_piece(str);
		if (e->xp > 150 || e->yp > 150)
			ft_error("Piece too big", 1);
	}
	if (str[0] == '.' || str[0] == '*')
		fill_piece(e, str);
}
