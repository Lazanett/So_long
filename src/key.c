/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:13 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/13 15:05:53 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tab_img(t_struc *nb)
{
	int	i;
	int	j;

	i = 0;
	convertion(nb);
	while (i < nb->ligne)
	{
		j = 0;
		while (j <= nb->colonne)
		{
			if (nb->tab[i][j] == '1')
			{
				mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->tree, (j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == '0')
			{
				mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, (j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == 'P')
			{
				mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_mr1, (j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == 'E')
			{
				mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, (j * nb->mini->img_width), (i * nb->mini->img_height));
			}
			if (nb->tab[i][j] == 'C')
			{
				mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->crystal, (j * nb->mini->img_width), (i * nb->mini->img_height));
				nb->collect++;
			}
			j++;
		}
		i++;
	}
}

void	convertion(t_struc *nb)
{
	nb->mini->crystal = mlx_xpm_file_to_image(nb->mini->mlx, CRYSTAL, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->exit = mlx_xpm_file_to_image(nb->mini->mlx, EXIT, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->herbe = mlx_xpm_file_to_image(nb->mini->mlx, HERBE, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->mini_tree = mlx_xpm_file_to_image(nb->mini->mlx, MINI_TREE, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->tree = mlx_xpm_file_to_image(nb->mini->mlx, TREE, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_bas = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_BAS, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_ml1 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML1, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_ml2 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML2, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_ml3 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML3, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_ml4 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML4, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_mr1 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR1, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_mr2 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR2, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_mr3 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR3, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_mr4 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR4, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enl1 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML1, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enl2 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML2, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enl3 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML3, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enl4 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML4, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enr1 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR1, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enr2 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR2, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enr3 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR3, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->enr4 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR4, &nb->mini->img_width, &nb->mini->img_height);
}

int	ft_key(int keycode, t_struc *nb)
{
	//(void) pos;
	//(void) mini;
	//
	
	if (keycode == XK_Escape)
	{
		
		mlx_destroy_display(nb->mini->mlx);
		mlx_destroy_window(nb->mini->mlx, nb->mini->window);
		//message erreur de count de mouvement
		//free
		exit(0);
	}
	if (keycode == XK_Up || keycode == XK_w)
	{
		move_up(nb);
	}	
	else if (keycode == XK_Left || keycode == XK_a)
	{
		move_left(nb);
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		move_right(nb);
	}
	else if (keycode == XK_Down || keycode == XK_s)
	{
		move_down(nb);
	}
	return (0);
}

/*int	ft_escape(int keycode, t_mini *mini)
{
	
	return (0);
}*/

int	ft_mouse(t_struc *nb)
{
	//count mouv;
	mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	mlx_destroy_display(nb->mini->mlx);
	//free
	exit(0);
}