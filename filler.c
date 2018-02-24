/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:30:25 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/15 14:02:51 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	map_coordinates(char *str, t_filler *f)
{
	while (!ft_isdigit(*str))
		str++;
	f->y_map = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	f->x_map = ft_atoi(str);
}

static char		**create_map(int fd, t_filler f)
{
	char	**map;
	char	*str;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (f.y_map + 1));
	get_next_line(fd, &str);
	ft_strdel(&str);
	while (i < f.y_map && get_next_line(fd, &str) == 1)
	{
		map[i] = ft_strdup(str + 4);
		i++;
		ft_strdel(&str);	
	}
	map[i] = NULL;
	return (map);
}

static void		piece_coordinates(char *str, t_filler *f)
{
	while (!ft_isdigit(*str))
		str++;
	f->y_piece = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	f->x_piece = ft_atoi(str);
}

static void		create_pieace(t_filler *f, int fd)
{
	char	*str;
	int		i; 

	i = 0;
	get_next_line(fd, &str);
	piece_coordinates(str, f);
	ft_strdel(&str);
	f->piece = (char **)malloc(sizeof(char *) * (f->y_piece + 1));
	while (i < f->y_piece && get_next_line(fd, &str) == 1)
	{
		f->piece[i] = ft_strdup(str);
		i++;
		ft_strdel(&str);
	}
	f->piece[i] = NULL;
}
			
int				main(void)
{
	t_filler	f;
	char		*str;
	int			fd;
	int			flag;

	//fd = 0;
	flag = 0;
	f = (t_filler){'\0','\0', 0, 0, 0, NULL, 0, 0, NULL, 0, 0, {0, 0}};
	fd = open("test", O_RDWR);
	get_next_line(fd, &str);
	f.player = (str[10] == '1') ? 'O' : 'X';
	f.bot = (str[10] == '2') ? 'O' : 'X';
	ft_strdel(&str);
	while (get_next_line(fd, &str) == 1)
	{
		map_coordinates(str, &f);
		ft_strdel(&str);
		f.map = create_map(fd, f);
		create_pieace(&f, fd);
		(flag++ == 0) ? find_min_x(&f) : 0;
		put_piece(&f);
	}
	return (0);
}
