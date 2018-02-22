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
	char	player;
	char	bot;
	char	**map;
	int		x_map;
	int		y_map;
	char	**piece;
	int		x_piece;
	int		y_piece;
	int		o_coordinate_x;
	int		o_coordinate_y;
	int		x_coordinate_x;
	int		x_coordinate_y; 
}				t_filler;

void		markup_map(t_filler *f);
void		put_piece(t_filler *f);
#endif
