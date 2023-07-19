/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:03:44 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/19 14:59:34 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		free_parsing(nb);
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
		free_parsing(nb);
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
		free_parsing(nb);
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
		free_parsing(nb);
		return (1);
	}

}

int	invalid_char(t_struc *nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb->ligne)
	{
		j = 0;
		while (j < nb->colonne)
		{
			if (nb->tab[i][j] != 'C' && nb->tab[i][j] != 'E' && \
				nb->tab[i][j] != '1' && nb->tab[i][j] != '0' \
				&& nb->tab[i][j] != 'P' && nb->tab[i][j] != '\n'\
				&& nb->tab[i][j] != '\0')
			{
				return (1);
				ft_putendl_fd("Error : invalid caractere", 2);
				free_parsing(nb);
			}
			j++;
		}
		i++;
	}
	return (0);
}