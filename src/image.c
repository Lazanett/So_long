/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:14:53 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/17 11:35:21 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	tab_img(t_struc *nb)
{
	int	i;
	int	j;

	i = 0;
	convertion_base(nb);
	while (i < nb->ligne - 1)
	{
		j = 0;
		while (j <= nb->colonne)
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
			j++;
		}
		i++;
	}
}

void	verif_img(t_struc *nb)
{
	ft_printf("probleme img\n");
	exit_game(nb);
	exit(0);
}

void	convertion_base(t_struc *nb)
{
	nb->mini->crystal = mlx_xpm_file_to_image(nb->mini->mlx, \
			CRYSTAL, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->crystal == NULL)
		verif_img(nb);
	nb->mini->exit = mlx_xpm_file_to_image(nb->mini->mlx, \
			EXIT, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->exit == NULL)
		verif_img(nb);
	nb->mini->herbe = mlx_xpm_file_to_image(nb->mini->mlx, \
			HERBE, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->herbe == NULL)
		verif_img(nb);
	nb->mini->tree = mlx_xpm_file_to_image(nb->mini->mlx, \
			TREE, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->tree == NULL)
		verif_img(nb);
	nb->mini->player_mr1 = mlx_xpm_file_to_image(nb->mini->mlx, \
			PLAYER_MR1, &nb->mini->img_width, &nb->mini->img_height);
	if (nb->mini->player_mr1 == NULL)
		verif_img(nb);
}
