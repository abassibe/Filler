/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 04:22:26 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/12 03:45:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			get_x_piece(t_fill *e, const char *str)
{
	if (ft_strncmp("Piece ", str, 6) == 0)
		e->xp = ft_atoi(&str[6]);
}

void			get_y_piece(t_fill *e, const char *str)
{
	int		i;

	i = 6;
	if (ft_strncmp("Piece ", str, 6) == 0)
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		i++;
		e->yp = ft_atoi(&str[i]);
	}
}

void			fill_piece(t_fill *e, const char *str)
{
	int		j;

	j = 0;
	if (str[0] == '.' || str[0] == '*')
	{
		while (j < 100)
			e->piece[e->len_p][j++] = 0;
		j = 0;
		while (str[j])
		{
			e->piece[e->len_p][j] = str[j];
			j++;
		}
		e->len_p++;
		if (e->len_p == e->xp)
			e->valid = 1;
	}
}

void			crea_piece(t_fill *e)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if (e->xp && e->yp && !e->piece)
	{
		if (!(tab = (char **)malloc(sizeof(char *) * 100)))
			ft_error("error malloc", 1);
		while (i < 100)
			if (!(tab[i++] = ft_strnew(100)))
				ft_error("error malloc", 1);
		e->piece = tab;
	}
}

void			fill_tab(t_fill *e, const char *str)
{
	int		y;
	int		x;

	y = -1;
	x = ft_atoi(str);
	while (++y < e->y)
		e->tab[x][y] = str[y + 4];
}
