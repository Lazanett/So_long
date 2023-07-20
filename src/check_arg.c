/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:09:48 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/20 14:14:50 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_argv(char *av, char *search)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (arg(av, search, i, len) == 0)
		return (0);
	return (1);
}

int	arg(char *av, char *search, int i, int len)
{
	if ((ft_strlen(av) - 4) == 4)
		error_name();
	if (len > 4)
	{
		len -= 4;
		while ((av[len] || search[i]) && av[len] == search[i])
		{
			len++;
			i++;
		}
	}
	if (search[i] == '\0')
		return (0);
	else
	{
		ft_putendl_fd("Error : invalid name of map", 2);
		exit(0);
		return (1);
	}
}

int	error_name(void)
{
	ft_putendl_fd("Error : invalid name of map", 2);
	exit(0);
	return (1);
}
