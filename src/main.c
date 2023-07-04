/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:36:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/04 10:19:51 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
}

int	main(int ac, char **av)
{
	t_struc	elem;
	//int	i;

	//i = 0;
	if (ac == 2 && check_argv(av[1], ".ber") == 0)
	{
		ft_init_struc(&elem);
		ft_init_tab(av[1], &elem); // == 0 alors on continue backtraking
		if (ft_size_map(&elem) == 0 && ft_map_available(&elem) == 0)
		{
			if (first_line(&elem) == 0 && left_col(&elem) == 0 && 
				right_col(&elem) == 0 && last_line(&elem) == 0)
			{
				printf("\ntout est ok");
			}
		}
	}
	else
		printf("mauvaises conditions");
	return (0);
}

int	check_argv(char *av, char *search) // verif fini par .ber  t que 
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(av);
	if (len > 8)
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
	printf("pas corespondance");
	return (1);
}