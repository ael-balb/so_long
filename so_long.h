/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:58:11 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/14 18:02:38 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
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

//libft

void	ft_putnbr(int nb);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);




#endif