/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:38:31 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 15:38:46 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	map[y - 1][x] = 'P';
	map[y][x] = '0';
	game->map->player->y--;
	game->counter++;
	ft_putstr_fd(YELLOW"\nMove : ", 1);
	ft_putnbr(game->counter);
}

void	move_down(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	map[y + 1][x] = 'P';
	map[y][x] = '0';
	game->map->player->y++;
	game->counter++;
	ft_putstr_fd(YELLOW"\nMove : ", 1);
	ft_putnbr(game->counter);
}

void	move_left(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	map[y][x - 1] = 'P';
	map[y][x] = '0';
	game->map->player->x--;
	game->counter++;
	ft_putstr_fd(YELLOW"\nMove : ", 1);
	ft_putnbr(game->counter);
}

void	move_right(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	map[y][x + 1] = 'P';
	map[y][x] = '0';
	game->map->player->x++;
	game->counter++;
	ft_putstr_fd(YELLOW"\nMove : ", 1);
	ft_putnbr(game->counter);
}