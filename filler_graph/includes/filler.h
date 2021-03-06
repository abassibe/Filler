/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 00:34:29 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/28 03:37:10 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../ressources/mlx.h"

typedef struct		s_fill
{
	char			player;
	char			adv;
	int				x;
	int				y;
	int				xp;
	int				yp;
	char			**tab;
	char			**piece;
	int				len_p;
	int				valid;
	int				save_x;
	int				save_y;
	int				range;
	int				save_px;
	int				save_py;
	void			*mlx;
	void			*win;
	void			*vimg;
	char			*img;
	int				sl;
	void			*vimg2;
	char			*img2;
	int				sl2;
	int				garb;
	int				draw;
	int				m_point;
	int				a_point;
	int				color;
}					t_fill;

void				ft_error(char *error, int k);
void				get_infos(t_fill *e, const char *str);
void				maj_data(t_fill *e, const char *str);
void				algo(t_fill *e);
void				check_range(t_fill *e, const int xt, const int yt);
void				mlx_set(t_fill *e);
void				draw_img(t_fill *e, const int x,
		const int y, const int color);
void				display_infos(t_fill *e);
void				draw_img_infos(t_fill *e, const int x, const int y,
		const int color);
void				draw_grid2(t_fill *e);
void				fill_white(t_fill *e);

#endif
