/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:36:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/12 15:01:50 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_struc	elem;
	t_pos	pos;
	t_mini	mini;

	if (ac == 2 && check_argv(av[1], ".ber") == 0)
	{
		ft_init_struc(&elem, &pos, &mini);
		ft_init_tab(av[1], &elem); // == 0 alors on continue backtraking
		if (ft_game_ok(&elem, &pos) == 0)
		{
			if (backtraking_ok(&elem, &pos) == 0)
			{
				mini.mlx = mlx_init();
				if (mini.mlx == NULL)
					return (1);
				mini.window = mlx_new_window(mini.mlx, ((elem.colonne - 1) * 32), ((elem.ligne - 1) * 32), "Game");
				tab_img(&elem, &mini);
			}
			mlx_hook(mini.window, KeyPress, 1L<<0, ft_escape, &mini);
			mlx_hook(mini.window, KeyPress, 1L<<0, ft_key, &mini);
			mlx_hook(mini.window, ClientMessage, 1L<<5, ft_mouse, &mini);
			mlx_loop(mini.mlx);
		}
	}
	else
		printf("mauvaises conditions");
	return (0);
}

int	check_argv(char *av, char *search) // verif fini par .ber  t que 
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	//if (len > 8)
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
	//printf("pas correspondance");
	return (1);
}