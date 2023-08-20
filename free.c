/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:31:25 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 18:43:27 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	free_game(void *clear)
{
	t_game	*game;

	game = (t_game *)clear;
	free(game->map->player);
	free(game->map->map);
	free(game->map);
	free(game);
	exit(0);
	return (1);
}