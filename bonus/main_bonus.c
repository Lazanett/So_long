/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:13:25 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/20 16:24:56 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_struc	elem;

	if (ac == 2 && check_argv(av[1], ".ber") == 0)
	{
		ft_init_struc(&elem);
		ft_init_tab(av[1], &elem);
		if (ft_game_bonus_ok(&elem) == 0)
		{
			if (backtraking_bonus_ok(&elem) == 0)
			{
				elem.mini->mlx = mlx_init();
				if (elem.mini->mlx == NULL)
					return (1);
				elem.mini->window = mlx_new_window(elem.mini->mlx, \
						((elem.colonne - 1) * 48), (elem.ligne * 48), "Game");
				tab_img_bonus(&elem);
				mlx_hook(elem.mini->window, KeyPress, 1L << 0, ft_key_b, &elem);
				mlx_hook(elem.mini->window, ClientMessage, 1L << 5, \
				ft_mouse_b, &elem);
				mlx_loop(elem.mini->mlx);
			}
		}
	}
	else
		ft_putendl_fd("Error : bad number of argument", 2);
}

int	ft_key_b(int keycode, t_struc *nb)
{
	if (keycode == XK_Escape)
	{
		exit_game_b(nb);
		exit(0);
	}
	if (keycode == XK_Up || keycode == XK_w)
		move_up_bonus(nb);
	else if (keycode == XK_Left || keycode == XK_a)
		move_left_bonus(nb);
	else if (keycode == XK_Right || keycode == XK_d)
		move_right_bonus(nb);
	else if (keycode == XK_Down || keycode == XK_s)
		move_down_bonus(nb);
	return (0);
}

int	ft_mouse_b(t_struc *nb)
{
	exit_game_b(nb);
	exit(0);
}

void	exit_game_b(t_struc *nb)
{
	clear_img_bonus(nb);
	if (nb->mini->window)
	{
		mlx_clear_window(nb->mini->mlx, nb->mini->window);
		mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	}
	mlx_destroy_display(nb->mini->mlx);
	free(nb->pos);
	free(nb->mini->mlx);
	free(nb->mini);
	ft_free(nb->tab);
	exit(0);
}

int	ft_game_bonus_ok(t_struc *nb)
{
	if (ft_size_map(nb) == 0)
	{
		if (ft_map_available(nb) == 0)
		{
			if (first_line(nb) == 0 && left_col(nb) == 0 && \
				right_col(nb) == 0 && last_line(nb) == 0 && \
				invalid_char_bonus(nb) == 0)
				return (0);
			else
			{
				ft_putendl_fd("Error : invalid caractere", 2);
				free_parsing(nb);
			}
		}
	}
	return (1);
}
