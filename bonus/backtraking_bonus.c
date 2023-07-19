/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:16:31 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/19 13:32:38 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	backtraking_bonus_ok(t_struc *nb)
{
	chemin_bonus(nb, nb->pos->p_ligne, nb->pos->p_col);
	if (nb->collect == 0 && nb->exit == 0)
	{
		ft_free(nb->tab_copy);
		return (0);
	}	
	else
	{
		ft_putendl_fd("backtraking impossible", 2);
		free_parsing(nb);
		return (1);
	}
}

void	chemin_bonus(t_struc *nb, int j, int i)
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
		if ((nb->tab_copy[j + 1][i] != '1' && nb->tab_copy[j + 1][i] != 'M')&& \
				nb->tab_copy[j + 1][i] != '\0')
			chemin_bonus(nb, j + 1, i);
		if ((nb->tab_copy[j][i + 1] != '1' && nb->tab_copy[j][i + 1] != 'M') && \
				nb->tab_copy[j][i + 1] != '\0')
			chemin_bonus(nb, j, i + 1);
		if ((nb->tab_copy[j - 1][i] != '1' && nb->tab_copy[j - 1][i] != 'M') && \
				nb->tab_copy[j - 1][i] != '\0')
			chemin_bonus(nb, j - 1, i);
		if ((nb->tab_copy[j][i - 1] != '1' && nb->tab_copy[j][i - 1] != 'M') && \
				nb->tab_copy[j][i - 1] != '\0')
			chemin_bonus(nb, j, i - 1);
		return ;
	}
}

int	invalid_char_bonus(t_struc *nb)

{
	int	i;
	int	j;

	i = 0;
	while (i < nb->ligne)
	{
		j = 0;
		while (j < nb->colonne)
		{
			if (nb->tab[i][j] != 'C' && nb->tab[i][j] != 'E' && \
				nb->tab[i][j] != '1' && nb->tab[i][j] != '0' \
				&& nb->tab[i][j] != 'P' && nb->tab[i][j] != '\n'\
				&& nb->tab[i][j] != 'M' && nb->tab[i][j] != '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
