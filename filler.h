/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:22:11 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/28 23:02:04 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define RESET  "\x1B[0m"
# define RED 	"\x1B[31m"
# define BLUE   "\x1B[34m"
# define GREEN  "\x1B[32m"
# define YELLOW "\x1B[33m"
# define PURPLE "\x1B[35m"
# include "./libft/ft_printf.h"

typedef struct			s_filler
{
	char				player;
	char				bot;
	int					pos_flag;
	char				**map;
	int					x_map;
	int					y_map;
	char				**piece;
	int					x_piece;
	int					y_piece;
	int					near[2];
}						t_filler;

typedef struct			s_flag
{
	int					i;
	int					j;
	int					a;
	int					b;
	int					flag;
	int					flag1;
	int					flag2;
	int					flag3;
}						t_flag;

typedef struct			s_options
{
	int					i;
	int					j;
	struct s_options	*next;
}						t_options;

void					put_piece(t_filler *f);
void					map_analyzer(t_filler *f);
void					put_final_coordinate(t_options **head, t_filler *f);
int						modul(int a);
void					free_all(t_filler *f, t_options **head);
#endif
