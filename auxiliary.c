/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyzer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:01:24 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/28 22:55:10 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
				return ;
			}
			j++;
		}
		i++;
	}
}

int			modul(int a)
{
	if (a >= 0)
		return (a);
	else
		a = -a;
	return (a);
}

void		free_all(t_filler *f, t_options **head)
{
	int			i;
	t_options	*current;
	t_options	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	i = 0;
	while (f->map[i])
	{
		ft_strdel(&(f->map[i]));
		i++;
	}
	i = 0;
	free(f->map);
	while (f->piece[i])
	{
		ft_strdel(&(f->piece[i]));
		i++;
	}
	free(f->piece);
}
