/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:20:10 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/20 12:24:03 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_exit_up(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_mr1, nb->pos->p_col * nb->mini->img_width, \
	(nb->pos->p_ligne - 1) * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}

void	move_exit_left(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_ml1, (nb->pos->p_col - 1) * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}

void	move_exit_right(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_mr1, (nb->pos->p_col + 1) * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}

void	move_exit_down(t_struc *nb)
{
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->player_bas, nb->pos->p_col * nb->mini->img_width, \
	(nb->pos->p_ligne + 1) * nb->mini->img_height);
	mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, \
	nb->mini->exit, nb->pos->p_col * nb->mini->img_width, \
	nb->pos->p_ligne * nb->mini->img_height);
}
