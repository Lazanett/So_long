/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:16:29 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/19 10:30:13 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tab_img_bonus(t_struc *nb)
{
	int	i;
	int	j;

	i = 0;
	convertion_base(nb);
	convertion(nb);
	while (i < nb->ligne)
	{
		j = 0;
		while (j <= nb->colonne && nb->tab[i][j] != '\0') // dire a will
		{
			//printf("%c\n", nb->tab[i][j]);
			if (nb->tab[i][j] == '1')
			{
				mlx_put_image_to_window(nb->mini->mlx, \
				nb->mini->window, nb->mini->tree, \
				(j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == '0')
			{
				mlx_put_image_to_window(nb->mini->mlx, \
				nb->mini->window, nb->mini->herbe, \
				(j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == 'P')
			{
				mlx_put_image_to_window(nb->mini->mlx, \
				nb->mini->window, nb->mini->player_mr1, \
				(j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == 'E')
			{
				mlx_put_image_to_window(nb->mini->mlx, \
				nb->mini->window, nb->mini->exit, \
				(j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == 'C')
			{
				mlx_put_image_to_window(nb->mini->mlx, \
				nb->mini->window, nb->mini->crystal, \
				(j * nb->mini->img_width), (i * nb->mini->img_height));
				nb->collect++;
			}
			if (nb->tab[i][j] == 'M')
			{
				mlx_put_image_to_window(nb->mini->mlx, \
				nb->mini->window, nb->mini->attack1, \
				(j * nb->mini->img_width), (i * nb->mini->img_height)); 
				// peut etre mettre animation monstre
			}
			j++;
		}
		i++;
	}
}


void	convertion(t_struc *nb)
{
	nb->mini->player_bas = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_BAS, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_bas == NULL)
		verif_img(nb);
	nb->mini->player_ml2 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML2, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_ml2 == NULL)
		verif_img(nb);
	nb->mini->player_ml3 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML3, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_ml3 == NULL)
		verif_img(nb);
	nb->mini->player_ml4 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML4, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_ml4 == NULL)
		verif_img(nb);
	nb->mini->player_mr2 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR2, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_mr2 == NULL)
		verif_img(nb);
	nb->mini->player_mr3 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR3, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_mr3 == NULL)
		verif_img(nb);
	nb->mini->player_mr4 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR4, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_mr4 == NULL)
		verif_img(nb);
	convertion_attack(nb);
}

void	convertion_attack(t_struc *nb)
{
	nb->mini->attack1 = mlx_xpm_file_to_image(nb->mini->mlx, ATTACK1, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->attack1 == NULL)
		verif_img(nb);
	nb->mini->attack2 = mlx_xpm_file_to_image(nb->mini->mlx, ATTACK2, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->attack2 == NULL)
		verif_img(nb);
	nb->mini->attack3 = mlx_xpm_file_to_image(nb->mini->mlx, ATTACK3, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->attack3 == NULL)
		verif_img(nb);
	nb->mini->attack4 = mlx_xpm_file_to_image(nb->mini->mlx, ATTACK4, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->attack4 == NULL)
		verif_img(nb);
}