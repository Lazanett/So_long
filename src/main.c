/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:36:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/11 12:59:05 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_struc	elem;
	t_pos	pos;
	t_mini	mini;
	//int	i;

	//i = 0;
	if (ac == 2 && check_argv(av[1], ".ber") == 0)
	{
		ft_init_struc(&elem);
		ft_init_struc2(&pos);
		ft_init_struc3(&mini);
		ft_init_tab(av[1], &elem); // == 0 alors on continue backtraking
		if (ft_size_map(&elem) == 0 && ft_map_available(&elem, &pos) == 0)
		{
			if (first_line(&elem) == 0 && left_col(&elem) == 0 && 
				right_col(&elem) == 0 && last_line(&elem) == 0)
			{
				//printf("\nside map ok");
				backtraking_ok(&elem, &pos, &mini);
				mini.mlx = mlx_init();
				mini.window = mlx_new_window(mini.mlx, (elem.colonne * 100), (elem.ligne * 100), "Game");
				mlx_hook(mini.window, KeyPress, 1L<<0, ft_key, &mini);
				mlx_hook(mini.window, ClientMessage, 1L<<5, ft_mouse, &mini);
				mlx_loop(mini.mlx);
			}
		}
	}
	else
		printf("mauvaises conditions");
	return (0);
}


void	ft_init_struc(t_struc *elem)
{
	elem->tab = NULL;
	elem->line = NULL;
	elem->fd = 0;
	elem->perso = 0;
	elem->exit = 0;
	elem->collect = 0;
	elem->ligne = 0;
	elem->colonne = 0;
	elem->start = '\0';
}

void	ft_init_struc2(t_pos *pos)
{
	pos->p_ligne = 0;
	pos->p_col = 0;
	pos->exit_ligne = 0;
	pos->exit_col = 0;
}

void	ft_init_struc3(t_mini *mini)
{
	mini->img_width = 100;
	mini->img_height = 100;
	mini->crystal = NULL;
	mini->filename = NULL;
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