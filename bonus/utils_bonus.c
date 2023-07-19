/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:17:59 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/19 11:18:53 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clear_img_bonus(t_struc *nb)
{
	if (nb->mini->crystal)
		mlx_destroy_image(nb->mini->mlx, nb->mini->crystal);
	if (nb->mini->exit)
		mlx_destroy_image(nb->mini->mlx, nb->mini->exit);
	if (nb->mini->herbe)
		mlx_destroy_image(nb->mini->mlx, nb->mini->herbe);
	if (nb->mini->tree)
		mlx_destroy_image(nb->mini->mlx, nb->mini->tree);
	if (nb->mini->player_mr1)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_mr1);
	if (nb->mini->player_ml1)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_ml1);
	if (nb->mini->player_bas)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_bas);
	clear_player(nb);
}

void	clear_player(t_struc *nb)
{
	if (nb->mini->player_ml2)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_ml2);
	if (nb->mini->player_ml3)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_ml3);
	if (nb->mini->player_ml4)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_ml4);
	if (nb->mini->player_mr2)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_mr2);
	if (nb->mini->player_mr3)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_mr3);
	if (nb->mini->player_mr4)
		mlx_destroy_image(nb->mini->mlx, nb->mini->player_mr4);
	clear_attack(nb);
}

void	clear_attack(t_struc *nb)
{
	if (nb->mini->attack1)
		mlx_destroy_image(nb->mini->mlx, nb->mini->attack1);
	if (nb->mini->attack2)
		mlx_destroy_image(nb->mini->mlx, nb->mini->attack2);
	if (nb->mini->attack3)
		mlx_destroy_image(nb->mini->mlx, nb->mini->attack3);
	if (nb->mini->attack4)
		mlx_destroy_image(nb->mini->mlx, nb->mini->attack4);
}