/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:36:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/20 12:18:34 by lazanett         ###   ########.fr       */
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
		if (ft_game_ok(&elem) == 0)
		{
			if (backtraking_ok(&elem) == 0)
			{
				elem.mini->mlx = mlx_init();
				if (elem.mini->mlx == NULL)
					return (1);
				elem.mini->window = mlx_new_window(elem.mini->mlx, \
						((elem.colonne - 1) * 48), (elem.ligne * 48), "Game");
				tab_img(&elem);
				mlx_hook(elem.mini->window, KeyPress, 1L << 0, ft_key, &elem);
				mlx_hook(elem.mini->window, ClientMessage, 1L << 5, ft_mouse, \
				&elem);
				mlx_loop(elem.mini->mlx);
			}
		}
	}
	else
		ft_putendl_fd("Error : bad number of argument", 2);
}

int	ft_game_ok(t_struc *nb)
{
	if (ft_size_map(nb) == 0)
	{
		if (ft_map_available(nb) == 0)
		{
			if (first_line(nb) == 0 && left_col(nb) == 0 && \
				right_col(nb) == 0 && last_line(nb) == 0 && \
				invalid_char(nb) == 0)
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
