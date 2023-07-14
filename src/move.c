/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:03:29 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/13 19:48:31 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_struc *nb)
{

	nb->pos->target_posl = nb->pos->p_ligne - 1;
	nb->pos->target_posc = nb->pos->p_col;
	//printf("%d = wight\n", nb->mini->img_width);
	//printf("%d = height\n", nb->mini->img_height);
	if (move_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, (nb->pos->p_col + 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		else
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, nb->pos->p_col * nb->mini->img_width, (nb->pos->p_ligne - 1) * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		nb->pos->p_ligne -= 1;
		nb->count_move++;
		ft_printf("%d = number of move\n", nb->count_move);
	}
}

void	move_left(t_struc *nb)
{
	nb->pos->target_posl = nb->pos->p_ligne;
	nb->pos->target_posc = nb->pos->p_col - 1;
	if (move_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, (nb->pos->p_col + 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		else
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, (nb->pos->p_col - 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		nb->pos->p_col -= 1;
		nb->count_move++;
		ft_printf("%d = number of move\n", nb->count_move);
	}
}

void	move_right(t_struc *nb)
{
	nb->pos->target_posl = nb->pos->p_ligne;
	nb->pos->target_posc = nb->pos->p_col + 1;
	if (move_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, (nb->pos->p_col + 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		else
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, (nb->pos->p_col + 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		nb->pos->p_col += 1;
		nb->count_move++;
		ft_printf("%d = number of move\n", nb->count_move);
	}
}

void	move_down(t_struc *nb)
{
	nb->pos->target_posl = nb->pos->p_ligne + 1;
	nb->pos->target_posc = nb->pos->p_col;
	if (move_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, (nb->pos->p_col + 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		else
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, nb->pos->p_col * nb->mini->img_width, (nb->pos->p_ligne + 1) * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		nb->pos->p_ligne += 1;
		nb->count_move++;
		ft_printf("%d = number of move\n", nb->count_move);
	}
}

int	move_ok(t_struc *nb)
{
	if (nb->collect == 0 && nb->tab [nb->pos->target_posl][nb->pos->target_posc] == 'E')
		victory(nb);
	if (nb->tab[nb->pos->target_posl][nb->pos->target_posc] == 'C')
	{
		nb->tab[nb->pos->target_posl][nb->pos->target_posc] = '0';
		nb->collect--;
	}
	if (nb->tab[nb->pos->target_posl][nb->pos->target_posc] == '1')
		return (1);
	return (0);
}