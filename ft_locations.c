/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:32:29 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 17:40:44 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_map(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	y_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	element_locations(char **map, int *loca, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				loca[0] = i;
				loca[1] = j;
			}
			j++;
		}
		i++;
	}
}

t_xy	*element_position(char **map, char c)
{
	t_xy	*player;
	int		i;
	int		j;

	i = 0;
	player = malloc(sizeof(t_xy));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				player->y = i;
				player->x = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}