/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:20:26 by lazanett          #+#    #+#             */
/*   Updated: 2023/06/28 15:39:38 by lazanett         ###   ########.fr       */
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

//--------------------------------PARSING_MAP.C-----------------------------//
int	ft_init_tab(char *av);
int	ft_count_line(int fd);
char**	ft_malloc_tab(char **tab, int len);
//--------------------------------------------------------------------------//

#endif