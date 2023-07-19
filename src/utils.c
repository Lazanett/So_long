/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:08:13 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/18 17:14:02 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	victory(t_struc *nb)
{
	nb->count_move++;
	ft_printf("%d = number of move\n", nb->count_move);
	clear_img(nb);
	if (nb->mini->window)
	{
		mlx_clear_window(nb->mini->mlx, nb->mini->window);
		mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	}
	mlx_destroy_display(nb->mini->mlx);
	free(nb->pos);
	free(nb->mini->mlx);
	free(nb->mini);
	//ft_free(nb->tab_copy);
	ft_free(nb->tab);
	exit (0);
}

void	exit_game(t_struc *nb)
{
	clear_img(nb);
	if (nb->mini->window)
	{
		mlx_clear_window(nb->mini->mlx, nb->mini->window);
		mlx_destroy_window(nb->mini->mlx, nb->mini->window);
	}
	mlx_destroy_display(nb->mini->mlx);
	free(nb->pos);
	free(nb->mini->mlx);
	free(nb->mini);
	//ft_free(nb->tab_copy);
	ft_free(nb->tab);
	exit(0);
}

void	free_parsing(t_struc *nb)
{
	ft_free(nb->tab);
	ft_free(nb->tab_copy);
	free(nb->pos);
	free(nb->mini);
	exit(0);
}

void	clear_img(t_struc *nb)
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
}