/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:36:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/13 15:01:26 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_struc	elem;
	//t_pos	pos;
	//t_mini	mini;

	if (ac == 2 && check_argv(av[1], ".ber") == 0)
	{
		ft_init_struc(&elem);//
		ft_init_tab(av[1], &elem);//
		if (ft_game_ok(&elem) == 0)//
		{
			if (backtraking_ok(&elem) == 0)
			{
				elem.mini->mlx = mlx_init();//
				if (elem.mini->mlx == NULL)
					return (1);
				elem.mini->window = mlx_new_window(elem.mini->mlx, ((elem.colonne - 1) * 32), (elem.ligne * 32), "Game");
				tab_img(&elem);//
			}
			//printf("%d\n",elem.pos->p_col);
			//printf("%d\n", elem.pos->p_ligne);
			//mlx_hook(mini.window, KeyPress, 1L<<0, ft_escape, &mini);
			mlx_hook(elem.mini->window, KeyPress, 1L<<0, ft_key, &elem);
			mlx_hook(elem.mini->window, ClientMessage, 1L<<5, ft_mouse, &elem.mini);
			mlx_loop(elem.mini->mlx);
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

int	victory(t_struc *nb)
{
	//afficher le count deplacement;
	//free le tab
	mlx_destroy_display(nb->mini->mlx);
	mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	free(nb->mini->mlx);
	exit (0);
}