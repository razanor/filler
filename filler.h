/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:22:11 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/15 18:43:40 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./printf/ft_printf.h"

typedef struct 	s_filler
{
	char			player;
	char			bot;
	char			**map;
	int				x_map;
	int				y_map;
	char			**piece;
	int				x_piece;
	int				y_piece;
	int				min[2];
}				t_filler;

typedef struct 	s_flag
{
	int 			i;
	int				j;
	int				a;
	int				b;
	int				flag;
	int				flag1;
	int				flag2;
}				t_flag;

void		put_piece(t_filler *f);
#endif
