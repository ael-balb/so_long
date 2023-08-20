/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:33:18 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 17:39:44 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checking_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	counter_elements(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	validation_elements(char **map)
{
	if (checking_elements(map) == 0)
	{
		ft_putstr_fd(RED"Error : strainger element :/\n", 2);
		return (0);
	}
	if (counter_elements(map, 'C') < 1)
	{
		ft_putstr_fd(RED"Error : there's no alteres ! :(\n", 2);
		return (0);
	}
	if (counter_elements(map, 'E') != 1)
	{
		ft_putstr_fd(RED"Error : you have more or less than one exit\n", 2);
		return (0);
	}
	if (counter_elements(map, 'P') != 1)
	{
		ft_putstr_fd(RED"Error : you have more or less than one player\n", 2);
		return (0);
	}
	return (1);
}