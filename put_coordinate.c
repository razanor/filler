/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:37:19 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/28 23:06:52 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		near_spot_begin(t_filler *f)
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

static void		near_spot_end(t_filler *f)
{
	int i;
	int j;
	int in;

	i = 0;
	j = 0;
	in = modul((f->y_map - 1) - f->near[0] + modul(f->x_map - 1) - f->near[1]);
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			if (f->map[i][j] == f->bot || f->map[i][j] == ft_tolower(f->bot))
			{
				if (in > modul(f->y_map - 1 - i) + modul(f->x_map - 1 - j))
				{
					in = modul(f->y_map - 1 - i) + modul(f->x_map - 1 - j);
					f->near[0] = i;
					f->near[1] = j;
				}
			}
			j++;
		}
		i++;
	}
}

static void		begin_end(t_filler *f)
{
	if (f->pos_flag == 0)
	{
		near_spot_end(f);
		f->pos_flag = 1;
	}
	else
	{
		near_spot_begin(f);
		f->pos_flag = 0;
	}
}

void			put_final_coordinate(t_options **head, t_filler *f)
{
	t_options	*tmp;
	int			index;
	int			i;
	int			j;

	begin_end(f);
	tmp = (*head);
	i = tmp->i;
	j = tmp->j;
	index = modul(i - f->near[0]) + modul(j - f->near[1]);
	while (tmp)
	{
		if (index > modul(tmp->i - f->near[0]) + modul(tmp->j - f->near[1]))
		{
			index = modul(tmp->i - f->near[0]) + modul(tmp->j - f->near[1]);
			i = tmp->i;
			j = tmp->j;
		}
		tmp = tmp->next;
	}
	ft_printf("%d %d\n", i, j);
	free_all(f, head);
}
