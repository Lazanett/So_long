/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:57:14 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/13 19:22:23 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_struc(t_struc *elem)
{
	elem->pos = malloc(sizeof(t_pos));
	elem->mini = malloc(sizeof(t_mini));
	elem->tab = NULL;
	elem->tab_copy = NULL;
	elem->line = NULL;
	elem->fd = 0;
	elem->perso = 0;
	elem->exit = 0;
	elem->collect = 0;
	elem->ligne = 0;
	elem->colonne = 0;
	elem->start = '\0';
	elem->count_move = 0;
	ft_init_struc2(elem);
}

void	ft_init_struc2(t_struc *elem)
{
	elem->pos->p_ligne = 0;
	elem->pos->p_col = 0;
	elem->pos->target_posl = 0;
	elem->pos->target_posc = 0;
	elem->pos->exit_ligne = 0;
	elem->pos->exit_col = 0;
	ft_init_struc3(elem);
}

void	ft_init_struc3(t_struc *elem)
{
	elem->mini->img_width = 48;
	elem->mini->img_height = 48;
	elem->mini->crystal = NULL;
	elem->mini->exit = NULL;
	elem->mini->herbe = NULL;
	elem->mini->mini_tree = NULL;
	elem->mini->tree = NULL;
	ft_init_player(elem);
	ft_init_ennemi(elem);
}

void	ft_init_player(t_struc *elem)
{
	elem->mini->player_bas = NULL;
	elem->mini->player_ml1 = NULL;
	elem->mini->player_ml2 = NULL;
	elem->mini->player_ml3 = NULL;
	elem->mini->player_ml4 = NULL;
	elem->mini->player_mr1 = NULL;
	elem->mini->player_mr2 = NULL;
	elem->mini->player_mr3 = NULL;
	elem->mini->player_mr4 = NULL;
}

void	ft_init_ennemi(t_struc *elem)
{
	elem->mini->enl1 = NULL;
	elem->mini->enl2 = NULL;
	elem->mini->enl3 = NULL;
	elem->mini->enl4 = NULL;
	elem->mini->enr1 = NULL;
	elem->mini->enr2 = NULL;
	elem->mini->enr3 = NULL;
	elem->mini->enr4 = NULL;
}
