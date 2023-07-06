/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:08:38 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/05 10:46:49 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	chemin(t_struc *nb, int j, int i)
{
	printf("-- %c\n",nb->tab[j][i]);
	if (nb->collect == 0 && nb->exit == 0)
		return;
	if (nb->tab[j][i] == 'C')
		nb->collect--;
	if (nb->tab[j][i] == 'E')
		nb->exit--;
	nb->tab[j][i] = '1';
	if (nb->tab[j + 1][i] != '1' && nb->tab[j + 1][i] != '\0') // droite
		chemin(nb, j + 1, i);
	if (nb->tab[j][i + 1] != '1' && nb->tab[j][i + 1] != '\0') // bas
		chemin(nb, j, i + 1);
	if (nb->tab[j - 1][i] != '1' && nb->tab[j - 1][i] != '\0') // gauche
		chemin(nb, j - 1, i);
	if (nb->tab[j][i - 1] != '1' && nb->tab[j][i - 1] != '\0') // haut
		chemin(nb, j, i - 1);
	return;


}

void	backtraking_ok(t_struc *nb, t_pos *pos)
{
	chemin(nb,  pos->p_ligne, pos->p_col);
	if (nb->collect == 0 && nb->exit == 0)
		return ;
	else
	{
		printf("error");
		exit(0);
	}
}