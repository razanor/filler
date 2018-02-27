/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:02:12 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/27 20:04:25 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static void		check_input(char *str)
{
	if (str[1] == '$')
	{
		if (str[10] == '1')
			printf(BLUE "%s\n" RESET, str);
		else if (str[10] == '2')
			printf(RED "%s\n" RESET, str);
	}
	if (ft_isdigit(str[0]))
	{
		while (*str)
		{
			if (*str == 'X')
				printf(RED "%c" RESET, *str);
			else if (*str == 'x')
				printf(GREEN "%c" RESET, *str);
			else if (*str == 'O')
				printf(BLUE "%c" RESET, *str);
			else if (*str == 'o')
				printf(YELLOW "%c" RESET, *str);
			else
				printf("%c", *str);
			str++;
		}
		printf("\n");
	}
}

static int		get_result(char *str)
{
	int		res;

	while (!ft_isdigit(*str))
		str++;
	res = ft_atoi(str);
	return (res);
}

static void		put_result(int x, int y)
{
	if (x > y)
		printf(BLUE "%s\n" RESET, "Player 1 WON");
	else if (x < y)
		printf(RED "%s\n" RESET, "Player 2 WON");
	else
		printf(PURPLE "%s\n" RESET, "DRAW");
}

int				main(void)
{
	char	*str;
	int		x;
	int		y;

	while ((get_next_line(0, &str) == 1))
	{
		check_input(str);
		if (str[0] == '=')
		{
			x = get_result(str);
			printf("%s\n", str);
			ft_strdel(&str);
			get_next_line(0, &str);
			printf("%s\n", str);
			y = get_result(str);
			put_result(x, y);
		}
		else if (str[0] == ' ' || str[0] == '.' || str[0] == '*'
			|| str[0] == 'P' || str[0] == '<')
			printf("%s\n", str);
		ft_strdel(&str);
	}
	return (0);
}
