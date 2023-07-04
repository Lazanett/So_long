# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 13:51:45 by lazanett          #+#    #+#              #
#    Updated: 2023/07/04 10:08:02 by lazanett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#NAME_BONUS= so_long_bonus

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g3

MFLAGS = -L -lft -lXext -lX11 -lm -lbsd

SRC =	src/main.c\
		src/parsing_map.c\
		src/side_map.c\

#SRC_BONUS = 

PATH_MLX = minilibx

LIBX = -L mlx_linux

LIBXFLAGS = -lXext -lX11

PATH_LIB = libft
LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

#OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:  $(NAME) #$(NAME_BONUS)#

#bonus:  $(NAME_BONUS)

$(NAME) : $(OBJ)
	@make -s -C $(PATH_MLX)
	@make -s -C $(PATH_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g
	@echo "\nCompilation OK\n"

$(NAME_BONUS) : $(OBJ_BONUS)
	@make -s -C $(PATH_MLX)
	@make -s -C $(PATH_LIB)
	$(CC) $(CFLAGS)  $(LIB) $(LIBX) $(LIBXFLAGS) -o $(NAME_BONUS) -g
	@echo "\nCompilation Bonus OK\n"
#$(OBJ_BONUS)#
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_MLX)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)
#	rm -f $(OBJ_BONUS)

fclean: clean
	make -C $(PATH_LIB) fclean
	make -C $(PATH_MLX) clean
	rm -f $(NAME)
#	rm -f $(NAME_BONUS)

re: fclean all

.PHONY:	all clean fclean re