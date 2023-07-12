/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:08:38 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/12 14:51:47 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	backtraking_ok(t_struc *nb, t_pos *pos)
{
	chemin(nb, pos->p_ligne, pos->p_col);
	if (nb->collect == 0 && nb->exit == 0)
		return (0);
	else
	{
		ft_perror("backtraking impossible");
		return (1);
	}	

}

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

