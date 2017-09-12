/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 00:34:29 by abassibe          #+#    #+#             */
/*   Updated: 2017/09/12 01:02:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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
	int				sbs;
	int				save_x;
	int				save_y;
	int				range;
	int				save_px;
	int				save_py;
	int				lborder;
	int				rborder;
	int fd;
}					t_fill;

void				ft_error(char *error, int k);
void				get_infos(t_fill *e, const char *str);
void				algo(t_fill *e);
void				crea_piece(t_fill *e);
void				fill_tab(t_fill *e, const char *str);
void				fill_piece(t_fill *e, const char *str);
void				get_x_piece(t_fill *e, const char *str);
void				get_y_piece(t_fill *e, const char *str);

#endif
