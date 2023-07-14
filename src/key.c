/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:13 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/14 16:50:47 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_key(int keycode, t_struc *nb)
{
	if (keycode == XK_Escape)
	{
		clear_img(nb);
		ft_free(nb->tab);
		ft_free(nb->tab_copy);
		mlx_destroy_display(nb->mini->mlx);
		mlx_destroy_window(nb->mini->mlx, nb->mini->window);
		//free(nb->mini->mlx);
		exit(0);
	}
	if (keycode == XK_Up || keycode == XK_w)
		move_up(nb);
	else if (keycode == XK_Left || keycode == XK_a)
		move_left(nb);
	else if (keycode == XK_Right || keycode == XK_d)
		move_right(nb);
	else if (keycode == XK_Down || keycode == XK_s)
		move_down(nb);
	return (0);
}

int	ft_mouse(t_struc *nb)
{
	clear_img(nb);
	ft_free(nb->tab);
	ft_free(nb->tab_copy);
	if (nb->mini->mlx)
		mlx_destroy_display(nb->mini->mlx);
	if (nb->mini->window)
	mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	//free(nb->mini->mlx);
	exit(0);
}
