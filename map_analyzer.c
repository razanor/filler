/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyzer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:01:24 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/24 21:01:39 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	near_spot(t_filler *f)
{
	int	i;
	int j;
	int	index;

	i = 0;
	j = 0;
	index = modul(0 - f->near[0]) + modul(0 - f->near[1]);
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			if (f->map[i][j] == f->bot || f->map[i][j] == ft_tolower(f->bot))
			{
				if (index > modul(0 - i) + modul(0 - j))
				{	
					index = modul(0 - i) + modul(0 - j);
					f->near[0] = i;
					f->near[1] = j;
				}	
			}
			j++;
		}
		i++;
	}
}

void		map_analyzer(t_filler *f)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			if (f->map[i][j] == f->bot || f->map[i][j] == ft_tolower(f->bot))
			{
				f->near[0] = i;
				f->near[1] = j;
				near_spot(f);
				return ;
			}
			j++;
		}
		i++;
	}
}

void		find_min_x(t_filler *f)
{
	int i;
	int j;
	int	bot;
	int player;

	i = 0;
	j = 0;
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			if (f->map[i][j] == f->player)
				player = j;
			if (f->map[i][j] == f->bot)
				bot = j;
			j++;
		}
		i++;
	}
	f->pos_flag = (player - bot > 0) ? MAX : MIN; // тут 
}