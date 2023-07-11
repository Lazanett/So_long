/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:13 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/11 13:12:43 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tab_img(t_struc *nb, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb->ligne)
	{
		j = 0;
		while (j < nb->colonne)
		{
			printf("coucou");
			if (nb->tab[i][j] == '1')
			{
				mini->filename = "./img_xpm/crystal.xpm";
				//printf("%d = width\n", mini->img_width);
				//printf("%d = width\n", mini->img_height);
				mini->crystal = mlx_xpm_file_to_image(mini->mlx, mini->filename, &mini->img_width, &mini->img_height);
				mlx_put_image_to_window(mini->mlx, mini->window, mini->filename, (i * mini->img_width), (j * mini->img_height));
			}
			j++;
		}
		i++;
	}
	//printf("%d\n", nb->colonne);
	//printf("%d\n", count);
	
}

/*void convertion(t_mini *mini)
{
	
}*/

int	ft_key(int keycode, t_mini *mini)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_display(mini->mlx);
		mlx_destroy_window(mini->mlx, mini->window);
		//message erreur de count de mouvement
		//free
		exit(0);
	}
	else if (keycode == XK_Up || keycode == XK_w)
	{
		//move vers le haut
	}	
	else if (keycode == XK_Left || keycode == XK_a)
	{
		//move gauche
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		//move droit
	}
		
	else if (keycode == XK_Down || keycode == XK_s)
	{
		//move bas
	}
	return (0);
}

int	ft_mouse(t_mini *mini)
{
	//count mouv;
	mlx_destroy_window(mini->mlx, mini->window);
	mlx_destroy_display(mini->mlx);
	//free
	exit(0);
}

