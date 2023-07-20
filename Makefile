# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 13:51:45 by lazanett          #+#    #+#              #
#    Updated: 2023/07/20 15:15:54 by lazanett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

NAME_BONUS=so_long_bonus

CC=@cc

CFLAGS= -Wall -Wextra -Werror -g3

MFLAGS = -L -lft -lXext -lX11 -lm -lbsd

SRC= 	src/main.c\
		src/parsing_map.c\
		src/check_arg.c\
		src/side_map.c\
		src/backtraking.c\
		src/key.c\
		src/init.c\
		src/move.c\
		src/image.c\
		src/utils.c\
		src/move_exit.c\
		src/init_tab.c\

SRC_BONUS = src/parsing_map.c\
			bonus/backtraking_bonus.c\
			bonus/image_bonus.c\
			bonus/main_bonus.c\
			bonus/move_bonus.c\
			bonus/move_exit_bonus.c\
			bonus/utils_bonus.c\
			src/check_arg.c\
			src/side_map.c\
			src/init_tab.c\
			src/key.c\
			src/init.c\
			src/move.c\
			src/move_exit.c\
			src/image.c\
			src/utils.c\
			

PATH_MLX = minilibx

LIBX = -L minilibx -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

PATH_LIB = libft
LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:  $(NAME)

bonus: $(NAME_BONUS)

$(NAME) : $(OBJ)
	@make -s -C $(PATH_MLX)
	@make -s -C $(PATH_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g
	@echo "\nCompilation OK\n"

$(NAME_BONUS) : $(OBJ_BONUS)
	@make -s -C $(PATH_MLX)
	@make -s -C $(PATH_LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) $(LIBX) $(LIBXFLAGS) -o $(NAME_BONUS) -g
	@echo "\nCompilation Bonus OK\n"

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_MLX)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	make -C $(PATH_LIB) fclean
	make -C $(PATH_MLX) clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY:	all clean fclean re
