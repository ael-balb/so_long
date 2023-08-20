/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:36:50 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 16:02:43 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	higher_walls(char **map)
{
	int		i;

	i = 1;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			ft_putstr_fd(RED"Error : higher wall !\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	lower_walls(char **map)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (map[len] != NULL)
		len++;
	while (map[len - 1][j])
	{
		if (map[len - 1][j] != '1')
		{
			ft_putstr_fd(RED"Error : lower wall !\n", 2);
			return (0);
		}
		j++;
	}
	return (1);
}

int	left_walls(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
		{
			ft_putstr_fd(RED"Error : left wall !\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	right_walls(char **map)
{
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	j = 0;
	while (map[j])
	{
		if (map[j][len - 1] != '1')
		{
			ft_putstr_fd(RED"Error : right wall !\n", 2);
			return (0);
		}
		j++;
	}
	return (1);
}