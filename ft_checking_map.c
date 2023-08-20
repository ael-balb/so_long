/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:34:19 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 17:39:11 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char **map)
{
	if (!checker_format(map) || !validation_elements(map))
		return (0);
	return (1);
}

char	**checking_map(char *path)
{
	char	**map;

	map = ft_reading_map(path);
	if (!map || !valid_map(map))
		exit (1);
	if (valid_path(path) == 0)
	{
		ft_putstr_fd(RED
			"Error : ditaha can't exit or can't eat all the alteres :(\n", 2);
		exit (1);
	}
	return (map);
}