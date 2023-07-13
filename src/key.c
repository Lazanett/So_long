/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:13 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/13 17:17:19 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

	// verif apres chaque assignation aue pas null  et revoyer un message d'erreur free tout et clear supprimer image et map...
int	ft_key(int keycode, t_struc *nb)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_display(nb->mini->mlx);
		mlx_destroy_window(nb->mini->mlx, nb->mini->window);
		//free
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
	mlx_destroy_display(nb->mini->mlx);
	mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	exit(0);
}