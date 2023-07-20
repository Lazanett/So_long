/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:03:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/20 12:27:43 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_malloc_tab(t_struc *elem)
{
	char	**tab;

	tab = malloc (sizeof (char *) * (elem->ligne + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

int	ft_size_map(t_struc *nb)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < (nb->ligne - 1))
	{
		j = 0;
		while (nb->tab[i][j] != '\n')
			j++;
		if (j == (nb->colonne - 1))
			count++;
		i++;
	}
	if (count == (nb->ligne -1))
		return (0);
	else
	{
		ft_putendl_fd("Error : size of map invalid", 2);
		free_parsing(nb);
		return (1);
	}
}

int	ft_map_available(t_struc *nb)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb->ligne)
	{
		j = 0;
		while (j < nb->colonne)
		{
			ft_map_available2(nb, i, j);
			j++;
		}
		i++;
	}
	if (nb->collect > 0 && nb->perso == 1 && nb->exit == 1)
		return (0);
	else
	{
		ft_putendl_fd("Error : number of element", 2);
		free_parsing(nb);
		return (1);
	}
}

void	ft_map_available2(t_struc *nb, int i, int j)
{
	if (nb->tab[i][j] == 'P')
	{
		nb->pos->p_ligne = i;
		nb->pos->p_col = j;
		nb->perso++;
	}
	if (nb->tab[i][j] == 'E')
	{
		nb->pos->exit_ligne = i;
		nb->pos->exit_col = j;
		nb->exit++;
	}
	if (nb->tab[i][j] == 'C')
		nb->collect++;
}
