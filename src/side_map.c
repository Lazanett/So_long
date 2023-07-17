/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:03:44 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/17 16:06:46 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_game_ok(t_struc *nb)
{
	if (ft_map_available(nb) == 0)
	{ 
		if (ft_size_map(nb) == 0)
		{
			if (first_line(nb) == 0 && left_col(nb) == 0 && 
			right_col(nb) == 0 && last_line(nb) == 0)
				return (0);
			else
				free_parsing(nb);
		
		}
		else
		free_parsing(nb);
	}
	else
		free_parsing(nb);
	return (1);
}

int	first_line(t_struc *nb)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < 1)
	{
		j = 0;
		while (j < (nb->colonne - 1)) // + \n
		{
			if (nb->tab[i][j] == '1')
				count++;
			j++;
		}
		i++;
	}
	if ((count + 1) == nb->colonne) // + \n
		return (0);
	else
	{
		ft_putendl_fd("Error : side map invalid", 2);
		return (1);
	}
}

int	left_col(t_struc *nb)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < nb->ligne)
	{
		j = 0;
		while (j == 0)
		{
			if (nb->tab[i][j] == '1')
				count++;
			j++;
		}
		i++;
	}
	if (count == nb->ligne)
		return (0);
	else
	{
		ft_putendl_fd("Error : side map invalid", 2);
		return (1);
	}
}

int	right_col(t_struc *nb)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < nb->ligne)
	{
		j = nb->colonne - 2; // - \n et \0
		while (j < nb->colonne)
		{
			if (nb->tab[i][j] == '1')
				count++;
			j += 2;
		}
		i++;
	}
	if (count == nb->ligne)
		return (0);
	else
	{
		ft_putendl_fd("Error : side map invalid", 2);
		return (1);
	}
}

int	last_line(t_struc *nb)
{
	int	i;
	int	j;
	int	count;

	i = (nb->ligne - 1);
	count = 0;
	j = 0;
	while (j < nb->colonne)
	{
		if (nb->tab[i][j] == '1')
			count++;
		j++;
	}
	if ((count + 1) == nb->colonne) // + \n
		return(0);
	else
	{
		ft_putendl_fd("Error : side map invalid", 2);
		return (1);
	}

}