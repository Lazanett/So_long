/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:20:26 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/13 17:16:26 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define CRYSTAL "img_xpm/crystal.xpm"
# define EXIT "img_xpm/exit.xpm"
# define HERBE "img_xpm/herbe.xpm"
# define MINI_TREE "img_xpm/mini_tree.xpm"
# define TREE "img_xpm/tree.xpm"
# define PLAYER_BAS "img_xpm/perso/move_bas.xpm"
# define PLAYER_ML1 "img_xpm/perso/moveL_1.xpm"
# define PLAYER_ML2 "img_xpm/perso/moveL_2.xpm"
# define PLAYER_ML3 "img_xpm/perso/moveL_3.xpm"
# define PLAYER_ML4 "img_xpm/perso/moveL_4.xpm"
# define PLAYER_MR1 "img_xpm/perso/moveR_1.xpm"
# define PLAYER_MR2 "img_xpm/perso/moveR_2.xpm"
# define PLAYER_MR3 "img_xpm/perso/moveR_3.xpm"
# define PLAYER_MR4 "img_xpm/perso/moveR_4.xpm"
# define ENNEMI_ML1 "img_xpm/ennemi/enL_1.xpm"
# define ENNEMI_ML2 "img_xpm/ennemi/enL_2.xpm"
# define ENNEMI_ML3 "img_xpm/ennemi/enL_3.xpm"
# define ENNEMI_ML4 "img_xpm/ennemi/enL_4.xpm"
# define ENNEMI_MR1 "img_xpm/ennemi/enR_1.xpm"
# define ENNEMI_MR2 "img_xpm/ennemi/enR_2.xpm"
# define ENNEMI_MR3 "img_xpm/ennemi/enR_3.xpm"
# define ENNEMI_MR4 "img_xpm/ennemi/enR_4.xpm"

typedef struct s_struc
{
	char	**tab;
	char	**tab_copy;
	char	*line;
	int		fd;
	int		perso;
	int		exit;
	int		collect;
	int		ligne;
	int		colonne;
	char	start;
	int		count_move;
	struct s_pos *pos;
	struct s_mini *mini;
}	t_struc;


typedef struct s_pos
{
	int	p_ligne;
	int	p_col;
	int	target_posl;
	int	target_posc;
	int	exit_ligne;
	int	exit_col;
}	t_pos;

typedef struct s_mini
{
	void	*mlx;
	void	*window;
	void	*crystal;
	void	*exit;
	void	*herbe;
	void	*mini_tree;
	void	*tree;
	void	*player_bas;
	void	*player_ml1;
	void	*player_ml2;
	void	*player_ml3;
	void	*player_ml4;
	void	*player_mr1;
	void	*player_mr2;
	void	*player_mr3;
	void	*player_mr4;
	void	*enl1;
	void	*enl2;
	void	*enl3;
	void	*enl4;
	void	*enr1;
	void	*enr2;
	void	*enr3;
	void	*enr4;
	int		img_width;
	int		img_height;

}	t_mini;

//--------------------------BACKTRAKING.C------------------------------------//
void	chemin(t_struc *nb, int j, int i);
int		backtraking_ok(t_struc *nb);
//--------------------------------------------------------------------------//

//----------------------------IMAGE.C---------------------------------------//
void	tab_img(t_struc *nb);
void	verif_img(t_struc *nb);
void	convertion(t_struc *nb);
void	convertion2(t_struc *nb);
void	convertion3(t_struc *nb);
//--------------------------------INIT.C------------------------------------//
void	ft_init_struc(t_struc *elem);
void	ft_init_struc2(t_struc *elem);
void	ft_init_struc3(t_struc *elem);
void	ft_init_player(t_struc *elem);
void	ft_init_ennemi(t_struc *elem);
//--------------------------------------------------------------------------//

//--------------------------------KEY.C------------------------------------//
int		ft_key(int keycode, t_struc *nb);
int		ft_mouse(t_struc *nb);
//--------------------------------------------------------------------------//

//--------------------------------MAIN.C------------------------------------//
int		check_argv(char *av, char *search);
int		victory(t_struc *nb);
//--------------------------------------------------------------------------//

//-----------------------MOVE.C---------------------------------------------//
void	move_up(t_struc *nb);
void	move_left(t_struc *nb);
void	move_right(t_struc *nb);
void	move_down(t_struc *nb);
int		move_ok(t_struc *nb);
//--------------------------------------------------------------------------//

//--------------------------------PARSING_MAP.C-----------------------------//
int		ft_init_tab(char *av, t_struc *elem);
int		ft_map_available(t_struc *nb);
int		ft_size_map(t_struc *nb);
int		first_line(t_struc *elem);
int		ft_count_line(t_struc *elem);
char	**ft_malloc_tab(t_struc *elem);
//--------------------------------------------------------------------------//

//--------------------------SIDE_MAP.C---------------------------------------//
int		ft_game_ok(t_struc *nb);
int		first_line(t_struc *nb);
int		left_col(t_struc *nb);
int		right_col(t_struc *nb);
int		last_line(t_struc *nb);
//--------------------------------------------------------------------------//

#endif