/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:13 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/12 12:34:00 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tab_img(t_struc *nb, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	convertion(mini);
	while (i < nb->ligne)
	{
		j = 0;
		while (j < nb->colonne)
		{
			//printf("coucou");
			if (nb->tab[i][j] == '1')
			{
				mlx_put_image_to_window(mini->mlx, mini->window, mini->crystal, (j * mini->img_width), (i * mini->img_height));
			}
			j++;
		}
		i++;
	}
	//printf("%d\n", nb->colonne);
	//printf("%d\n", count);
	
}

void	convertion(t_mini *mini)
{
	mini->crystal = mlx_xpm_file_to_image(mini->mlx, CRYSTAL, &mini->img_width, &mini->img_height);
	mini->exit = mlx_xpm_file_to_image(mini->mlx, EXIT, &mini->img_width, &mini->img_height);
	mini->herbe = mlx_xpm_file_to_image(mini->mlx, HERBE, &mini->img_width, &mini->img_height);
	mini->mini_tree = mlx_xpm_file_to_image(mini->mlx, MINI_TREE, &mini->img_width, &mini->img_height);
	mini->tree = mlx_xpm_file_to_image(mini->mlx, TREE, &mini->img_width, &mini->img_height);
	mini->player_bas = mlx_xpm_file_to_image(mini->mlx, PLAYER_BAS, &mini->img_width, &mini->img_height);
	mini->player_ml1 = mlx_xpm_file_to_image(mini->mlx, PLAYER_ML1, &mini->img_width, &mini->img_height);
	mini->player_ml2 = mlx_xpm_file_to_image(mini->mlx, PLAYER_ML2, &mini->img_width, &mini->img_height);
	mini->player_ml3 = mlx_xpm_file_to_image(mini->mlx, PLAYER_ML3, &mini->img_width, &mini->img_height);
	mini->player_ml4 = mlx_xpm_file_to_image(mini->mlx, PLAYER_ML4, &mini->img_width, &mini->img_height);
	mini->player_mr1 = mlx_xpm_file_to_image(mini->mlx, PLAYER_MR1, &mini->img_width, &mini->img_height);
	mini->player_mr2 = mlx_xpm_file_to_image(mini->mlx, PLAYER_MR2, &mini->img_width, &mini->img_height);
	mini->player_mr3 = mlx_xpm_file_to_image(mini->mlx, PLAYER_MR3, &mini->img_width, &mini->img_height);
	mini->player_mr4 = mlx_xpm_file_to_image(mini->mlx, PLAYER_MR4, &mini->img_width, &mini->img_height);
	mini->enl1 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_ML1, &mini->img_width, &mini->img_height);
	mini->enl2 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_ML2, &mini->img_width, &mini->img_height);
	mini->enl3 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_ML3, &mini->img_width, &mini->img_height);
	mini->enl4 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_ML4, &mini->img_width, &mini->img_height);
	mini->enr1 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_MR1, &mini->img_width, &mini->img_height);
	mini->enr2 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_MR2, &mini->img_width, &mini->img_height);
	mini->enr3 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_MR3, &mini->img_width, &mini->img_height);
	mini->enr4 = mlx_xpm_file_to_image(mini->mlx, ENNEMI_MR4, &mini->img_width, &mini->img_height);
}

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