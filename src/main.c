/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:36:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/13 18:29:42 by lazanett         ###   ########.fr       */
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
				elem.mini->window = mlx_new_window(elem.mini->mlx, ((elem.colonne - 1) * 32), (elem.ligne * 32), "Game");
				tab_img(&elem);
			}
			mlx_hook(elem.mini->window, KeyPress, 1L<<0, ft_key, &elem);
			mlx_hook(elem.mini->window, ClientMessage, 1L<<5, ft_mouse, &elem);
			mlx_loop(elem.mini->mlx);
		}
	}
	else
	{
		ft_putendl_fd("Error : bad number of argument", 2);
		exit(0);
	}	
	return (0);
}

int	check_argv(char *av, char *search) // verif ca a la fin
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

int	victory(t_struc *nb)
{
	nb->count_move++;
	ft_printf("%d = number of move\n", nb->count_move);
	mlx_destroy_display(nb->mini->mlx);
	mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	free(nb->mini->mlx);
	exit (0);
}