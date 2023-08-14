/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheking_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:10:25 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/14 18:13:56 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_validated(char **map)
{
	if (!format_checker(map) || !elements_verification(map))
		return (0);
	return (1);
}

char	**ft_cheking_map(char *path)
{
	char	**map;

	map = ft_read_map(path);
	if (!map || !is_map_validated(map))
		exit (1);
	if (path_checker(path) == 0)
	{
		ft_putstr_fd(RED
			"Error : taha can't exit or can't eat all the burgers :(\n", 2);
		exit (1);
	}
	return (map);
}