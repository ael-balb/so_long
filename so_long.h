/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:42:09 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 16:30:02 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

# define RED    "\033[1m\033[31m"
# define GREEN    "\033[1m\033[32m"
# define YELLOW    "\033[1m\033[33m"

typedef struct coordinates
{
	int	x;
	int	y;
}	t_xy;

typedef struct map
{
	char			**map;
	int				x;
	int				y;
	int				c;
	t_xy			*player;
}	t_map;

typedef struct game
{
	void	*mlx;
	void	*window;
	void	*img;
	int		win_size;
	int		counter;
	t_map	*map;
}	t_game;

void	free_map(char **map);
int		free_game(void *alias);

int	    x_map(char **map);
int		y_map(char **map);
void	element_locations(char **map, int *coo, char c);
t_xy	*element_position(char **map, char c);

int		checking_elements(char **map);
int		counter_elements(char **map, char c);
int		validation_elements(char **map);

char	**checking_map(char *map_path);

int		extension_checker(char *ext);
int		checker_format(char **map);

char	**ft_reading_map(char *path);

int		higher_walls(char **map);
int		lower_walls(char **map);
int		right_walls(char **map);
int		left_walls(char **map);

void	ft_putnbr(int nb);

void	ft_putstr_fd(char *str, int fd);

char	**ft_split(char const *s, char c);

int		ft_strcmp(const char *str1, const char *str2);

char	*ft_strrchr(const char *s, int c);

int		key_hook(int key, t_game *game);

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

int		valid_path(char *path);

void	player_move_up(t_game *game);
void	player_move_down(t_game *game);
void	player_move_left(t_game *game);
void	player_move_right(t_game *game);

void	apply_textures(t_game *game);

t_map	*map_initialiser(char *path);

void	gagner(t_game *game);

#endif