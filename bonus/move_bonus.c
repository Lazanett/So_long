/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:27:39 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/19 12:47:04 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up_bonus(t_struc *nb)
{
	nb->pos->target_posl = nb->pos->p_ligne - 1;
	nb->pos->target_posc = nb->pos->p_col;
	if (move_bonus_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'M')
			game_over(nb);
		else if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_mr1, nb->pos->p_col* nb->mini->img_width, (nb->pos->p_ligne - 1) * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		else
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_mr1, nb->pos->p_col * nb->mini->img_width, (nb->pos->p_ligne - 1) * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		nb->pos->p_ligne -= 1;
		nb->count_move++;
		ft_printf("%d = number of move\n", nb->count_move);
	}
}

void	move_left_bonus(t_struc *nb)
{
	nb->pos->target_posl = nb->pos->p_ligne;
	nb->pos->target_posc = nb->pos->p_col - 1;
	if (move_bonus_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'M')
			game_over(nb);
		else if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_ml1, (nb->pos->p_col - 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		else
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_ml1, (nb->pos->p_col - 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		nb->pos->p_col -= 1;
		nb->count_move++;
		ft_printf("%d = number of move\n", nb->count_move);
	}
}

void	move_right_bonus(t_struc *nb)
{
	nb->pos->target_posl = nb->pos->p_ligne;
	nb->pos->target_posc = nb->pos->p_col + 1;
	if (move_bonus_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'M')
			game_over(nb);
		else if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_mr1, (nb->pos->p_col + 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->exit, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		else
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_mr1, (nb->pos->p_col + 1) * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->herbe, nb->pos->p_col * nb->mini->img_width, nb->pos->p_ligne * nb->mini->img_height);
		}
		nb->pos->p_col += 1;
		nb->count_move++;
		ft_printf("%d = number of move\n", nb->count_move);
	}
}

void	move_down_bonus(t_struc *nb)
{
	nb->pos->target_posl = nb->pos->p_ligne + 1;
	nb->pos->target_posc = nb->pos->p_col;
	if (move_bonus_ok(nb) == 0)
	{
		if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'M')
			game_over(nb);
		else if (nb->tab[nb->pos->p_ligne][nb->pos->p_col] == 'E')
		{
			mlx_put_image_to_window(nb->mini->mlx, nb->mini->window, nb->mini->player_bas, nb->pos->p_col * nb->mini->img_width, (nb->pos->p_ligne + 1)* nb->mini->img_height);
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

int	move_bonus_ok(t_struc *nb)
{
	//printf("coucou move bonus ok");
	if (nb->collect == 0 && nb->tab [nb->pos->target_posl][nb->pos->target_posc] == 'E')
		victory_bonus(nb);
	if (nb->tab[nb->pos->target_posl][nb->pos->target_posc] == 'C')
	{
		nb->tab[nb->pos->target_posl][nb->pos->target_posc] = '0';
		nb->collect--;
	}
	if (nb->collect != 0 && nb->tab [nb->pos->target_posl][nb->pos->target_posc] == 'E')
		return (0);
	if (nb->tab[nb->pos->target_posl][nb->pos->target_posc] == '1')
		return (1);
	if (nb->tab [nb->pos->target_posl][nb->pos->target_posc] == 'M')
		game_over(nb);
	return (0);
}
