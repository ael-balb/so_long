/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:38:03 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 19:44:44 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *game)
{
	if (key == 65307 || key < 0)
		exit(0);
	//mlx_clear_window(game->mlx, game->window);
	if (key == 65361 || key == 97)
		player_move_left(game);
	if (key == 65363 || key == 100)
		player_move_right(game);
	if (key == 65362 || key == 119)
		player_move_up(game);
	if (key == 65364 || key == 155)
		player_move_down(game);
	apply_textures(game);
	return (0);
}