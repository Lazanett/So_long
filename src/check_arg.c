/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:09:48 by lazanett          #+#    #+#             */
/*   Updated: 2023/07/18 12:10:15 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_argv(char *av, char *search)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (check_absolu(av, "map/", len) == 1)
	{
		if (ft_strlen(av) == 4)
		{
			ft_putendl_fd("Error : the map have no name", 2);
			exit(0);
			return (1);
		}
		if (len > 4)
		{
			len -= 4;
			while ((av[len] || search[i]) && av[len] == search[i])
			{
				len++;
				i++;
			}
		}
	}
	if (search[i] == '\0')
		return (0);
	else
	{
		ft_putendl_fd("Error : not .ber", 2);
		exit(0);
		return (1);
	}
}

int	check_absolu(char *av, char *search, int len)
{
	int	i;

	i = 0;
	while ((av[i] && search[i]) && av[i] == search[i])
		i++;
	if (i == 4)
	{
		if (ft_strlen(av) == 8)
		{
			ft_putendl_fd("Error : the map have no name", 2);
			exit(0);
			return (1);
		}
		if (len > 8)
		{
			len -= 4;
			while ((av[len] || search[i]) && av[len] == search[i])
			{
				len++;
				i++;
			}
		}
	}
	return (1);
}