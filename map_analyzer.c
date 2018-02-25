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

static void	max_bot(t_filler *f)
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
				if (f->near[1] < j)
				{
					f->near[0] = i;
					f->near[1] = j;
				}
			}
			j++;
		}
		i++;
	}
}

static void	min_bot(t_filler *f)
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
				if (f->near[1] >= j)
				{
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
			}
			j++;
		}
		i++;
	}
	if (f->pos_flag == MAX)
		max_bot(f);
	if (f->pos_flag == MIN)
		min_bot(f);
}

void		find_min_x(t_filler *f)
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
			if (f->map[i][j] == f->player)
				f->p_start = j;
			if (f->map[i][j] == f->bot)
				f->b_start = j;
			j++;
		}
		i++;
	}
	f->pos_flag = (f->p_start - f->b_start > 0) ? MAX : MIN;
}