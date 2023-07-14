/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:14:53 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/14 10:32:59 by lazanett         ###   ########.fr       */
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
			printf("%d = wight\n", nb->mini->img_width);
			printf("%d = height\n", nb->mini->img_height);
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
				mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, (j * nb->mini->img_width), (i * nb->mini->img_height));
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

void	verif_img(t_struc *nb)
{
	//ft_perror("probleme img");
	mlx_destroy_display(nb->mini->mlx);
	mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	exit(0);
}

void	convertion(t_struc *nb)
{
	nb->mini->crystal = mlx_xpm_file_to_image(nb->mini->mlx, CRYSTAL, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->exit = mlx_xpm_file_to_image(nb->mini->mlx, EXIT, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->herbe = mlx_xpm_file_to_image(nb->mini->mlx, HERBE, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->player_bas = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_BAS, &nb->mini->img_width, &nb->mini->img_height);
	nb->mini->tree = mlx_xpm_file_to_image(nb->mini->mlx, TREE, &nb->mini->img_width, &nb->mini->img_height);
	
}

/*void	convertion(t_struc *nb)
{
	printf("%d = wight\n", nb->mini->img_width);
	printf("%d = height\n", nb->mini->img_height);
	nb->mini->crystal = mlx_xpm_file_to_image(nb->mini->mlx, CRYSTAL, &nb->mini->img_width, &nb->mini->img_height);
	printf("%d = wight\n", nb->mini->img_width);
	printf("%d = height\n", nb->mini->img_height);
	//if (nb->mini->crystal == NULL)
	//	verif_img(nb);
	nb->mini->exit = mlx_xpm_file_to_image(nb->mini->mlx, EXIT, &nb->mini->img_width, &nb->mini->img_height);
	printf("%d = wight\n", nb->mini->img_width);
	printf("%d = height\n", nb->mini->img_height);
	//if (nb->mini->exit == NULL)
	//	verif_img(nb);
	nb->mini->herbe = mlx_xpm_file_to_image(nb->mini->mlx, HERBE, &nb->mini->img_width, &nb->mini->img_height);
	printf("%d = wight\n", nb->mini->img_width);
	printf("%d = height\n", nb->mini->img_height);
	//if (nb->mini->herbe == NULL)
	//	verif_img(nb);
	//nb->mini->mini_tree = mlx_xpm_file_to_image(nb->mini->mlx, MINI_TREE, &nb->mini->img_width, &nb->mini->img_height);
	//nb->mini->tree = mlx_xpm_file_to_image(nb->mini->mlx, TREE, &nb->mini->img_width, &nb->mini->img_height);
	//if (nb->mini->tree == NULL)
	//	verif_img(nb);
	nb->mini->player_bas = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_BAS, &nb->mini->img_width, &nb->mini->img_height);
	printf("%d = wight\n", nb->mini->img_width);
	printf("%d = height\n", nb->mini->img_height);
	//if (nb->mini->player_bas == NULL)
	//	verif_img(nb);
	//nb->mini->player_ml1 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML1, &nb->mini->img_width, &nb->mini->img_height);
	//if (nb->mini->player_ml1 == NULL)
	//	verif_img(nb);
	//nb->mini->player_ml2 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML2, &nb->mini->img_width, &nb->mini->img_height);
	//if (nb->mini->player_ml2 == NULL)
	//	verif_img(nb);
	//convertion2(nb); 
}*/

void	convertion2(t_struc *nb) // perd 48
{
	//printf("%d = wight\n", nb->mini->img_width);
	//printf("%d = height\n", nb->mini->img_height);
	nb->mini->player_ml3 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML3, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_ml3 == NULL)
		verif_img(nb);
	nb->mini->player_ml4 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_ML4, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_ml4 == NULL)
		verif_img(nb);
	nb->mini->player_mr1 = mlx_xpm_file_to_image(nb->mini->mlx, PLAYER_MR1, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_mr1 == NULL)
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
	nb->mini->enl1 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML1, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->enl1 == NULL)
		verif_img(nb);
	nb->mini->enl2 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML2, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->enl2 == NULL)
		verif_img(nb);
	//convertion3(nb);
}

void	convertion3(t_struc *nb) // pbm des 2 derniere images ennemi initialisation 
{
	nb->mini->enl3 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML3, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->enl3 == NULL)
		verif_img(nb);
	nb->mini->enl4 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_ML4, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->enl2 == NULL)
		verif_img(nb);
	nb->mini->enr1 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR1, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->enr1 == NULL)
		verif_img(nb);
	nb->mini->enr2 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR2, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->enr2 == NULL)
		verif_img(nb);
	//nb->mini->enr3 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR3, &nb->mini->img_width, &nb->mini->img_height);
	//if (nb->mini->enr3 == NULL)
	//	verif_img(nb);
	//ft_printf("TEST");
	//nb->mini->enr4 = mlx_xpm_file_to_image(nb->mini->mlx, ENNEMI_MR4, &nb->mini->img_width, &nb->mini->img_height);
	//if (nb->mini->enr4 == NULL)
	//	verif_img(nb);
	
	
}