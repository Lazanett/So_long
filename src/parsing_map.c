/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:03:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/12 12:06:35 by lazanett         ###   ########.fr       */
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
			//printf("%s", elem->line);
			elem->tab[elem->ligne] = elem->line;
			elem->tab_copy[elem->ligne] = elem->line;
			printf("%s", elem->tab_copy[elem->ligne]);
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
	elem->tab = malloc (sizeof (char *) * (elem->ligne + 1));
	if (!elem->tab)
		return (NULL);
	return (elem->tab);
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
	while (i < nb->ligne)
	{
		j = 0;
		while (j < nb->colonne)
		{
			j++;
			if (i == 0)
				j_temp = j;
		}
		if (j_temp == j)
			count++;
		i++;
	}
	if (count == nb->ligne)
	{
		//printf("OK");
		return (0);
	}	
	else
		return (1);
}

int	ft_map_available(t_struc *nb, t_pos *data) 
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
				data->p_ligne = i;
				data->p_col = j;
				nb->perso++;
			}
			if (nb->tab[i][j] == 'E')
			{
				data->exit_ligne = i;
				data->exit_col= j;
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
		return (1);
}
