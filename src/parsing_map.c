/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:03:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/04 10:12:09 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_init_tab(char *av, t_struc *elem)
{
	//int		j;

	//j = 0;
	elem->fd = open(av, O_RDONLY);
	if (elem->fd == -1)
		return (1);
	elem->ligne = ft_count_line(elem);
	close(elem->fd);
	elem->fd = open(av, O_RDONLY);
	if (elem->fd == -1)
		return (1);
	elem->tab = ft_malloc_tab(elem);
	elem->ligne = 0;
	if (elem->tab)
	{
		elem->line = get_next_line(elem->fd);
		elem->colonne = ft_strlen(elem->line);
		//printf("%d = colonne\n", elem->colonne);
		while (elem->line)
		{
			printf("%s", elem->line);
			elem->tab[elem->ligne++] = elem->line;
			//free(elem->line);
			elem->line = get_next_line(elem->fd);
		}
		elem->tab[elem->ligne] = NULL;
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
	if (nb->ligne < 4 || nb->ligne >= nb->colonne) // prectangle et depalcement potable
		return (1);//voir avec will
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

int	ft_map_available(t_struc *nb) 
{
	int	i;
	int	j;

	i = 0;
	//printf("\n%i= ligne\n ", nb->ligne);
	//printf("%i = colonne \n", nb->colonne);
	while (i < nb->ligne)
	{
		j = 0;
		while (j < nb->colonne)
		{
			if (nb->tab[i][j] == 'P')
				nb->perso++;
			if (nb->tab[i][j] == 'E')
				nb->exit++;
			if (nb->tab[i][j] == 'C')
				nb->collect++;
			//printf("%c\n", nb->tab[i][j]);
			j++;
		}
		i++;
	}
	//printf("\n%d = nb de perso\n", nb->perso);
	//printf("%d = nb de exit\n", nb->exit);
	//printf("%d = nb de collect\n", nb->collect);
	if (nb->collect > 0 && nb->perso == 1 && nb->exit == 1)
		return (0);
	else
		return (1);
}
/*{
		if (ft_strncmp(*elem[i].tab, "P", i) == 0)
			
		if (ft_strncmp(*elem[i].tab, "P", i) == 0)
			elem->exit++;
		if (ft_strncmp(*elem[i].tab, "P", i) == 0)
			elem->collect++;
		i++;
	}
	
	
}*/

/*int	first_line(t_struc *elem)
{
	int	count_char;
	int i;
	bool valid;

	count_char = 0;
	i = 0;
	valid = true;
	//elem->line = get_next_line(elem->fd);
	while (elem->line[i])
	{
		if (elem->line[i] != '1')
		{
			valid = false;
			break;
		}
		i++;
	}
	// printf("%i\n", i);
	// printf("%i\n", count_char);
	// if (i == count_char)
	// {
	// 	ft_putendl_fd("first line OK", 1); /// voir
	// 	return (1);
	// }
	// ft_putendl_fd("first line KO", 1);
	if (valid)
		return (1);
	else
		return (0);
}*/

