/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:16:22 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/20 15:24:44 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up_exit_bonus(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_mr1, nb->pos->p_col * nb->mini->img_width, \
	(nb->pos->p_ligne - 1) * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}

void	move_left_exit_bonus(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_ml1, (nb->pos->p_col - 1) * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}

void	move_right_exit_bonus(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_mr1, (nb->pos->p_col + 1) * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}

void	move_down_exit_bonus(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_bas, nb->pos->p_col * nb->mini->img_width, \
	(nb->pos->p_ligne + 1) * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}
