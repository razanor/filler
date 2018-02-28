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
SRC = filler.c check_piece.c auxiliary.c put_coordinate.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@ echo "-----------------------------------"
	@ echo "nrepak.filler is ready to fight"
	@ cd ./libft && make && mv $(LIB) ..
	@ gcc $(OBJ) $(LIB) $(FLAGS) -o $(NAME)
	@ gcc $(FLAGS) -o bonus bonus.c $(LIB)
%.o: %.c
	@ gcc $(FLAGS) -c $<
clean:
	@ echo "-----------------------------------"
	@ echo "Objects files are removed"
	@ /bin/rm -rf $(OBJ)
	@ cd ./libft && make clean
fclean: clean
	@ echo "-----------------------------------"
	@ echo "nrepak.filler is deleted"
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ /bin/rm -f bonus
	@ cd ./libft && make fclean
re: fclean all
