/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:40:48 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 19:19:12 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture(t_game *game, int x, int y)
{
	char	*path;

	if (game->map->map[x][y] == 'E')
		path = "textures/E.xpm";
	else if (game->map->map[x][y] == '1')
		path = "textures/1.xpm";
	else if (game->map->map[x][y] == '0')
		path = "textures/0.xpm";
	else if (game->map->map[x][y] == 'C')
		path = "textures/C.xpm";
	else if (game->map->map[x][y] == 'P')
		path = "textures/P.xpm";
	else
		return ;
	game->img = mlx_xpm_file_to_image (game->mlx, path,
			&game->win_size, &game->win_size);
	if (!game->img)
	{
		ft_putstr_fd(RED"Error : texture not found !\n", 2);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img, y * 50, x * 50);
	mlx_destroy_image(game->mlx, game->img);
}

void	apply_textures(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map->map[x])
	{
		y = 0;
		while (game->map->map[x][y] != '\n' && game->map->map[x][y])
		{
			put_texture(game, x, y);
			y++;
		}
		x++;
	}
}