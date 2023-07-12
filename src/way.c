/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:08:38 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/12 12:19:06 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*void	tab_copy(t_struc *nb)
{
	int i = 0;
	printf("%d = ligne \n", nb->ligne);
	nb->tab_copy = malloc(sizeof(char *) * (nb->ligne + 1));
	if (!nb->tab_copy)
		printf("pas de copy 1");
	while (i <= nb->ligne)
	{
		nb->tab_copy[i] = nb->tab[i];
		printf("%s\n",nb->tab_copy[i]);
		i++;
	}
	//nb->tab[i] = NULL;
}*/

void	chemin(t_struc *nb, int j, int i)
{
	if (nb->tab_copy)
	{
		//printf("%d\n", nb->ligne);
		//printf("-- %c\n",nb->tab_copy[j][i]);
		if (nb->collect == 0 && nb->exit == 0)
			return;
		if (nb->tab_copy[j][i] == 'C')
			nb->collect--;
		if (nb->tab_copy[j][i] == 'E')
			nb->exit--;
		nb->tab_copy[j][i] = '1';
		if (nb->tab_copy[j + 1][i] != '1' && nb->tab_copy[j + 1][i] != '\0') // droite
			chemin(nb, j + 1, i);
		if (nb->tab_copy[j][i + 1] != '1' && nb->tab_copy[j][i + 1] != '\0') // bas
			chemin(nb, j, i + 1);
		if (nb->tab_copy[j - 1][i] != '1' && nb->tab_copy[j - 1][i] != '\0') // gauche
			chemin(nb, j - 1, i);
		if (nb->tab_copy[j][i - 1] != '1' && nb->tab_copy[j][i - 1] != '\0') // haut
			chemin(nb, j, i - 1);
		return ;
	}
}

void	backtraking_ok(t_struc *nb, t_pos *pos, t_mini *mini)
{

	chemin(nb, pos->p_ligne, pos->p_col);
	if (nb->collect == 0 && nb->exit == 0)
	{
		tab_img(nb, mini);
	}
	else
	{
		printf("error");
		exit(0);
	}
}