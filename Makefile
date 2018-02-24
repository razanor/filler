# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrepak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 12:26:27 by nrepak            #+#    #+#              #
#    Updated: 2018/02/13 12:26:31 by nrepak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nrepak.filler
FLAGS = -Wall -Wextra -Werror
LIB = libftprintf.a
SRC = filler.c put_piece.c map_analyzer.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@ cd ./printf && make && mv $(LIB) ..
	@ gcc $(OBJ) $(LIB) $(FLAGS) -o $(NAME)
%.o: %.c
	@ gcc $(FLAGS) -c $<
clean:
	@ /bin/rm -rf $(OBJ)
	@ cd ./printf && make clean
fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ cd ./printf && make fclean
re: fclean all
