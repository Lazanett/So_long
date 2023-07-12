/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:57:14 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/12 13:57:47 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_struc(t_struc *elem, t_pos *pos, t_mini *mini)
{
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
	ft_init_struc2(pos, mini);
}

void	ft_init_struc2(t_pos *pos, t_mini *mini)
{
	pos->p_ligne = 0;
	pos->p_col = 0;
	pos->exit_ligne = 0;
	pos->exit_col = 0;
	ft_init_struc3(mini);
}

void	ft_init_struc3(t_mini *mini)
{
	mini->img_width = 32;
	mini->img_height = 32;
	mini->crystal = NULL;
	mini->exit = NULL;
	mini->herbe = NULL;
	mini->mini_tree = NULL;
	mini->tree = NULL;
	ft_init_player(mini);
	ft_init_ennemi(mini);
}

void	ft_init_player(t_mini *mini)
{
	mini->player_bas = NULL;
	mini->player_ml1 = NULL;
	mini->player_ml2 = NULL;
	mini->player_ml3 = NULL;
	mini->player_ml4 = NULL;
	mini->player_mr1 = NULL;
	mini->player_mr2 = NULL;
	mini->player_mr3 = NULL;
	mini->player_mr4 = NULL;
}

void	ft_init_ennemi(t_mini *mini)
{
	mini->enl1 = NULL;
	mini->enl2 = NULL;
	mini->enl3 = NULL;
	mini->enl4 = NULL;
	mini->enr1 = NULL;
	mini->enr2 = NULL;
	mini->enr3 = NULL;
	mini->enr4 = NULL;
}
