/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:36:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/14 16:46:34 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_struc	elem;

	if (check_argv(av[1], ".ber") == 0 && ac == 2)
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
			}
			mlx_hook(elem.mini->window, KeyPress, 1L<<0, ft_key , &elem);
			mlx_hook(elem.mini->window, ClientMessage, 1L<<5, ft_mouse , &elem);
			mlx_loop(elem.mini->mlx);
		}
		ft_free(elem.mini->mlx);
		exit (0);
	}
	else
	{
		ft_putendl_fd("Error : bad number of argument", 2);
		exit(0);
	}	
	return (0);
}

int	check_argv(char *av, char *search)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (len > 4)
	{
		len -= 4;
		while ((av[len] || search[i]) && av[len] == search[i])
		{
			len++;
			i++;
		}
	}
	if (search[i] == '\0')
		return (0);
	else
	{
		ft_putendl_fd("Error : not .ber", 2);
		exit(0);
		return (1);
	}
}
