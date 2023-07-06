/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:20:26 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/04 17:42:05 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_struc
{
	char	**tab;
	char	*line;
	int		fd;
	int		perso;
	int		exit;
	int		collect;
	//int		way;
	int		ligne;
	int		colonne;
	char	start;
}	t_struc;


typedef struct s_pos
{
	int	p_ligne;
	int	p_col;
	int	exit_ligne;
	int	exit_col;
}	t_pos;

typedef struct s_mini
{
	void	*mlx;
	void	*window;

}	t_mini;

//--------------------------------MAIN.C------------------------------------//
void	ft_init_struc(t_struc *elem);
void	ft_init_struc2(t_pos *pos);
int		check_argv(char *av, char *search);

//--------------------------------------------------------------------------//

//--------------------------------PARSING_MAP.C-----------------------------//
int		ft_init_tab(char *av, t_struc *elem);
int		ft_map_available(t_struc *elem, t_pos *data);
int		ft_size_map(t_struc *nb);
int		first_line(t_struc *elem);
int		ft_count_line(t_struc *elem);
char	**ft_malloc_tab(t_struc *elem);
//--------------------------------------------------------------------------//

//--------------------------SIDE_MAP.C---------------------------------------//
int	first_line(t_struc *nb);
int	left_col(t_struc *nb);
int	right_col(t_struc *nb);
int	last_line(t_struc *nb);
//--------------------------------------------------------------------------//

//--------------------------WAY.C-------------------------------------------//
void	chemin(t_struc *nb, int j, int i);
void backtraking_ok(t_struc *nb, t_pos *pos);
//--------------------------------------------------------------------------//

#endif