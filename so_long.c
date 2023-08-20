/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:41:34 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 19:18:48 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_initialiser(char *path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = checking_map(path);
	map->x = x_map(map->map);
	map->y = y_map(map->map);
	map->c = counter_elements(map->map, 'C');
	map->player = element_position(map->map, 'P');
	return (map);
}

t_game	*put_parameters(t_map *map)
{
	t_game	*exe;

	exe = malloc(sizeof(t_game));
	if (!exe)
	{
		ft_putstr_fd(RED"Error : allocation failed\n", 2);
		return (0);
	}
	exe->mlx = mlx_init();
	exe->window = mlx_new_window(exe->mlx, map->x * 50, map->y * 50, "so_long");
	exe->map = map;
	exe->win_size = 50;
	exe->counter = 0;
	return (exe);
}

int	main(int ac, char **av)
{
	t_game	*exe;
	t_map	*map;

	if (ac < 2)
	{
		ft_putstr_fd(RED"Error : please give a map !\n", 2);
		return (0);
	}
	if (ac > 2)
	{
		ft_putstr_fd(RED"Error : only one map please !\n", 2);
		return (0);
	}
	if (!extension_checker(av[1]))
		return (0);
	map = map_initialiser(av[1]);
	if (!map)
		return (0);
	exe = put_parameters(map);
	if (!exe)
		return (0);
	apply_textures(exe);
	mlx_key_hook(exe->window, &key_hook, exe);
	mlx_hook(exe->window, 17, 0, free_game, exe);
	mlx_loop(exe->mlx);
}