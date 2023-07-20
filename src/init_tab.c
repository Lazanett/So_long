/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:25:44 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/20 12:27:52 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_tab(char *av, t_struc *elem)
{
	open_map(elem, av);
	init_tab_malloc(elem);
	if (elem->tab && elem->tab_copy)
	{
		elem->line = get_next_line(elem->fd);
		if (elem->line)
		{
			elem->colonne = ft_strlen(elem->line);
			while (elem->line)
			{
				elem->tab[elem->ligne] = ft_strdup(elem->line);
				elem->tab_copy[elem->ligne] = ft_strdup(elem->line);
				elem->ligne++;
				free(elem->line);
				elem->line = get_next_line(elem->fd);
			}
			free(elem->line);
			elem->tab[elem->ligne] = NULL;
			elem->tab_copy[elem->ligne] = NULL;
		}
		else
			empty_tab(elem);
	}
	close(elem->fd);
}

void	init_tab_malloc(t_struc *elem)
{
	elem->tab = ft_malloc_tab(elem);
	elem->tab_copy = ft_malloc_tab(elem);
	elem->ligne = 0;
}

int	open_map(t_struc *elem, char *av)
{
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
	return (0);
}

void	empty_tab(t_struc *elem)
{
	close(elem->fd);
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
