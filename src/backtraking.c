/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:08:38 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/18 17:20:20 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	backtraking_ok(t_struc *nb)
{
	chemin(nb, nb->pos->p_ligne, nb->pos->p_col);
	ft_free(nb->tab_copy);
	if (nb->collect == 0 && nb->exit == 0)
		return (0);
	else
	{
		ft_putendl_fd("backtraking impossible", 2);
		return (1);
	}
}

void	chemin(t_struc *nb, int j, int i)
{
	if (nb->tab_copy)
	{
		if (nb->collect == 0 && nb->exit == 0)
			return ;
		if (nb->tab_copy[j][i] == 'C')
			nb->collect--;
		if (nb->tab_copy[j][i] == 'E')
			nb->exit--;
		nb->tab_copy[j][i] = '1';
		if (nb->tab_copy[j + 1][i] != '1' && \
				nb->tab_copy[j + 1][i] != '\0')
			chemin(nb, j + 1, i);
		if (nb->tab_copy[j][i + 1] != '1' && \
				nb->tab_copy[j][i + 1] != '\0')
			chemin(nb, j, i + 1);
		if (nb->tab_copy[j - 1][i] != '1' && \
				nb->tab_copy[j - 1][i] != '\0')
			chemin(nb, j - 1, i);
		if (nb->tab_copy[j][i - 1] != '1' && \
				nb->tab_copy[j][i - 1] != '\0')
			chemin(nb, j, i - 1);
		return ;
	}
}
