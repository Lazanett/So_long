# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 13:51:45 by lazanett          #+#    #+#              #
#    Updated: 2023/07/04 17:36:52 by lazanett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

CC=@cc

CFLAGS= -Wall -Wextra -Werror -g3

MFLAGS = -L -lft -lXext -lX11 -lm -lbsd

SRC= 	src/main.c\
		src/parsing_map.c\
		src/side_map.c\
		src/way.c\

PATH_MLX = minilibx

LIBX = -L minilibx -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

PATH_LIB = libft
LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

all:  $(NAME) $(NAME_BONUS)

$(NAME) : $(OBJ)
	@make -s -C $(PATH_MLX)
	@make -s -C $(PATH_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g
	@echo "\nCompilation OK\n"

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_MLX)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(PATH_LIB) fclean
	make -C $(PATH_MLX) clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
