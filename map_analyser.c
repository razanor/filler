/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:54:29 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/17 11:54:54 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	piece_coordinates(char *str, t_filler *f)
{
	while (!ft_isdigit(*str))
		str++;
	f->x_piece = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	f->y_piece = ft_atoi(str);
}

void	map_analyser(t_filler *f, int fd)
{
	char	*str;
	int		i; 

	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		if (str[0] == 'P' && str[1] == 'i')
			piece_coordinates(str, f);
		f->piece = (char **)malloc(sizeof(char *) * (f->x_piece + 1));
		while (i < f->x_piece && get_next_line(fd, &str) == 1)
		{
			f->piece[i] = ft_strdup(str);
			i++;
		}
		f->piece[i] = NULL;
		int a = 0;
		while (f->map[a])
		{
			ft_printf("%s\n", f->map[a]);
			a++;
		}
		a = 0;
		while (f->piece[a])
		{
			ft_printf("%s\n", f->piece[a]);
			a++;
		}
		ft_printf("%d\n", f->x_map);
		ft_printf("%d\n", f->y_map);
		//f->player == 'X' ? write (1, "")
	}
}