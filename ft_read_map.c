/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:05:42 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/14 18:06:40 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(void)
{
	ft_putstr_fd(RED"Error : empty or incorfirmed map \n", 2);
	exit (1);
}

char	**read_map(char *path)
{
	char	*line;
	char	*map;
	char	**mapholder;
	int		fd;

	fd = open (path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_strdup("");
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		map = ft_strjoin(map, line);
		free(line);
	}
	close(fd);
	if (map[0] == '\0' || map[map_x(&map) - 1] == '\n')
		error_msg();
	mapholder = ft_split(map, '\n');
	free(map);
	return (mapholder);
}
