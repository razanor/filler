/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analizator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:05:23 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/22 13:05:40 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	markup_map(t_filler *f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			if (f->map[i][j] == f->bot || f->map[i][j] == ft_tolower(f->bot))
				f->map[i][j] = '0';
			else if (f->map[i][j] == f->player || f->map[i][j] == ft_tolower(f->player))
				f->map[i][j] = '1';
			else
				f->map[i][j] = '|';
			j++;
		}
		i++;
	}
}

void	put_piece(t_filler *f)
{
	int i;
	int j;
	int a;
	int b;
	int flag;

	i = 0;
	j = 0;
	a = 0;
	b = 0;
	flag = 0;
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			a = 0;
			while (f->piece[a])
			{
				b = 0;
				while (f->piece[a][b])
				{
					if (f->piece[a][b] == '*' && i + a < f->y_map && j + b < f->x_map) 
					{
						if (f->map[i + a][j + b] == '1' && f->map[i + a][j + b] != '0')
							flag++;
					}
					b++;
				}
				a++;
			}
			if (flag == 1)
				ft_printf("%d %d\n", i, j); // here
			j++;
		}
		i++;
	}
	// printf("i = %d\n", i);
	// printf("j = %d\n", j);
	// printf("a = %d\n", a);
	// printf("b = %d\n", b);
	
}