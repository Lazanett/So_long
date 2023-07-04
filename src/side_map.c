/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:03:44 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/04 10:18:16 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	first_line(t_struc *nb)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (i < 1)
	{
		j = 0;
		while (j < (nb->colonne - 1)) // + \n
		{
			if (nb->tab[i][j] == '1')
				count++;
			//printf("\n%c = ligne %d colonne %d\n", nb->tab[i][j], i, j);
			j++;
		}
		i++;
	}
	//printf("%d\n", nb->colonne);
	//printf("%d\n", count);
	if ((count + 1) == nb->colonne) // + \n
	{
		//printf("\n1ere ligne ok");
		return(0);
	}
	return (1);
}

int	left_col(t_struc *nb)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (i < nb->ligne)
	{
		j = 0;
		while (j == 0)
		{
			//printf("\n%c ==  en position ligne %d et colone %d\n", nb->tab[i][j], i, j);
			if (nb->tab[i][j] == '1')
				count++;
			j++;
		}
		i++;
	}
	//printf("%d\n", nb->ligne);
	//printf("%d\n", count);
	if (count == nb->ligne)
	{
		//printf("\ncolonne de gauche ok");
		return(0);
	}
	return (1);
}

int	right_col(t_struc *nb)
{
	int	i;
	int	j;
	int count;

	i = 0;
	count = 0;
	while (i < nb->ligne)
	{
		j = nb->colonne - 2; // - \n et \0
		while (j < nb->colonne)
		{
			//j = nb->colonne - 2;
			//printf("\n%c ==  en position ligne %d et colone %d\n", nb->tab[i][j], i, j);
			if (nb->tab[i][j] == '1')
				count++;
			j += 2;
		}
		i++;
	}
	//printf("%d\n", nb->ligne);
	//printf("%d\n", count);
	if (count == nb->ligne)
	{
		//printf("\ncolonne de droite ok");
		return (0);
	}
	return (1);
}

int	last_line(t_struc *nb)
{
	int	i;
	int	j;
	int count;

	i = (nb->ligne - 1);
	count = 0;
	j = 0;
	while (j < nb->colonne)
	{
		if (nb->tab[i][j] == '1')
			count++;
		j++;
		//printf("%c\n", nb->tab[i][j]);
	}
	//printf("%d\n", nb->colonne);
	//printf("%d\n", count);
	if ((count + 1) == nb->colonne) // + \n
	{
		//printf("\nlast ligne ok");
		return(0);
	}
	return (1);
}