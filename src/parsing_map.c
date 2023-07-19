/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:03:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/19 16:03:31 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_init_tab(char *av, t_struc *elem)
{
	int	i;

	i = 0;
	elem->fd = open(av, O_RDONLY);
	if (elem->fd == -1)
	{
		ft_putendl_fd("Error : open map impossible", 2);
		free(elem->mini);
		free(elem->pos);
		exit(0);
		return (1);
	}
	elem->ligne = ft_count_line(elem);
	//printf("%d count line\n", elem->ligne);
	close(elem->fd);
	elem->fd = open(av, O_RDONLY);
	if (elem->fd == -1)
	{
		ft_putendl_fd("Error : open map impossible", 2);
		free(elem->mini);
		free(elem->pos);
		exit(0);
		return (1);
	}
	elem->tab = ft_malloc_tab(elem);
	elem->tab_copy = ft_malloc_tab(elem);
	elem->ligne = 0;
	if (elem->tab && elem->tab_copy)
	{
		elem->line = get_next_line(elem->fd);
		if (elem->line)
		{
			elem->colonne = ft_strlen(elem->line);
			//printf("%d\n", elem->colonne);
			while (elem->line)
			{
				elem->tab[elem->ligne] = ft_strdup(elem->line);
				elem->tab_copy[elem->ligne] = ft_strdup(elem->line);
				elem->ligne++;
				//printf("%s", elem->line);
				free(elem->line);
				elem->line = get_next_line(elem->fd);
			}
			free(elem->line);
			elem->tab[elem->ligne] = NULL;
			elem->tab_copy[elem->ligne] = NULL;
		}
		else
		{
			close(elem->fd);
			empty_tab(elem);
		}
	}
	close(elem->fd);
	return (0);
}


void	empty_tab(t_struc *elem)
{
	free(elem->tab);
	free(elem->tab_copy);
	free(elem->pos);
	free(elem->mini);
	ft_putendl_fd("Error : no array", 2);
	exit(0);
}

int	ft_count_line(t_struc *elem)
{
	int	count;

	count = 0;
	elem->line = get_next_line(elem->fd);
	while (elem->line)
	{		
		count++;
		free(elem->line);
		elem->line = get_next_line(elem->fd);
	}
	free(elem->line);
	return (count);
}

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
			ft_printf("%c", nb->tab[i][j]);
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
		ft_putendl_fd("Error : number of element", 2);
		free_parsing(nb);
		return (1);
	}
}
