/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:03:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/14 15:01:51 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_init_tab(char *av, t_struc *elem)
{
	elem->fd = open(av, O_RDONLY);
	if (elem->fd == -1)
		return (1);
	elem->ligne = ft_count_line(elem);
	close(elem->fd);
	elem->fd = open(av, O_RDONLY);
	if (elem->fd == -1)
		return (1);
	elem->tab = ft_malloc_tab(elem);
	elem->tab_copy = ft_malloc_tab(elem);
	elem->ligne = 0;
	if (elem->tab && elem->tab_copy)
	{
		elem->line = get_next_line(elem->fd);
		elem->colonne = ft_strlen(elem->line);
		while (elem->line)
		{
			elem->tab[elem->ligne] = ft_strdup(elem->line);
			elem->tab_copy[elem->ligne] = ft_strdup(elem->line);
			//printf("%s", elem->line);
			elem->line = get_next_line(elem->fd);
			elem->ligne++;
		}
		elem->tab[elem->ligne] = NULL;
		elem->tab_copy[elem->ligne] = NULL;
	}
	close(elem->fd);
	return (0);
}

int	ft_count_line(t_struc *elem)
{
	int	count;

	count = 0;
	elem->line = get_next_line(elem->fd);
	while (elem->line)
	{		
		count++;
		elem->line = get_next_line(elem->fd);
	}
	return (count);
}

char	**ft_malloc_tab(t_struc *elem)
{
	char **tab;
	tab = malloc (sizeof (char *) * (elem->ligne + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

int	ft_size_map(t_struc *nb)
{
	int	i;
	int	j;
	int	j_temp;
	int	count;

	i = 0;
	j_temp = 0;
	count = 0;
	//printf("%d\n",nb->ligne);
	
	//printf("%d\n",nb->colonne);
	while (i < (nb->ligne - 1))
	{
		j = 0;
		while (nb->tab[i][j] != '\n')
			j++;
		//printf("%d\n", j);
		if (j == (nb->colonne - 1))
			count++;
		i++;
	}
	if (count == (nb->ligne -1 ))
		return (0);
	else
	{
		ft_putendl_fd("Error : size of map invalide", 2);
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
			j++;
		}
		i++;
	}
	if (nb->collect > 0 && nb->perso == 1 && nb->exit == 1)
		return (0);
	else
	{
		ft_putendl_fd("Error : nb of exit not ok or nb of perso or nb of collectible", 2);
		exit(0);
		return (1);
	}
		
}
