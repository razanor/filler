/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:37:19 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/27 21:37:30 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		modul(int a)
{
	if (a >= 0)
		return (a);
	else
		a = -a;
	return (a);
}

void	put_final_coordinate(t_options **head, t_filler *f)
{
	t_options	*tmp;
	int			index;
	int			i;
	int			j;

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
}