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
	int i;

	i = 0;
	while (!ft_isdigit(*str))
		str++;
	f->x_map = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	f->y_map = ft_atoi(str);
}

static char		**create_map(int fd, t_filler f)
{
	char	**map;
	char	*str;
	int		i;
	char	*p;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (f.x_map + 1));
	while (f.x_map && get_next_line(fd, &str) == 1)
	{
		if (ft_isdigit(str[0]) && (p = ft_strchr(str, '.')))
		{
			map[i] = ft_strdup(p);
			f.x_map--;
			i++;
		}
		ft_strdel(&str);
	}
	map[i] = NULL;
	return (map);
}
			
int				main(void)
{
	t_filler	f;
	char		*str;
	int			fd;

	f = (t_filler){'\0', NULL, 0, 0, NULL, 0, 0, 0, 0, 0, 0};
	fd = open("test", O_RDWR);
	get_next_line(fd, &str);
	f.player = (str[10] == '1') ? 'X' : 'O';
	ft_strdel(&str);
	get_next_line(fd, &str);
	map_coordinates(str, &f);
	ft_strdel(&str);
	f.map = create_map(fd, f);
	map_analyser(&f, fd);
	return (0);
}
