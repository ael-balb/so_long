/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:39:30 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 16:28:00 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *mapc)
{
	if ((map[x][y] != 'P' && map[x][y] != '0' && map[x][y] != 'C')
		|| (x < 0 || y < 0 || x >= mapc[0] || y >= mapc[1]))
		return ;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y, mapc);
	flood_fill(map, x - 1, y, mapc);
	flood_fill(map, x, y + 1, mapc);
	flood_fill(map, x, y - 1, mapc);
}

int	exit_checker(char **map, int x, int y)
{
	if (map[x + 1][y] == 'F' || map[x - 1][y] == 'F'
		|| map[x][y + 1] == 'F' || map[x][y - 1] == 'F')
		return (1);
	else
		return (0);
}

int	valid_path(char *path)
{
	char	**map;
	int		p[2];
	int		mapc[2];
	int		exitc[2];
	
	map = ft_reading_map(path);
	element_locations(map, p, 'P');
	element_locations(map, exitc, 'E');
	mapc[0] = y_map(map);
	mapc[1] = x_map(map);
	flood_fill(map, p[0], p[1], mapc);
	if ((counter_elements(map, 'C') != 0)
		|| (exit_checker(map, exitc[0], exitc[1]) == 0))
	{
		free_map(map);
		return (0);
	}
	else
	{
		free_map(map);
		return (1);
	}
}