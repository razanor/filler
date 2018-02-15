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

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc > 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = NULL;

	while ((get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
