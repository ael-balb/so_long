/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:42:39 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/19 16:04:23 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gagner(t_game *game)
{
	if (game->map->c == 0)
	{
		ft_putstr_fd(GREEN"\nCongratulations !\n", 1);
		exit(0);
	}
	ft_putstr_fd(RED"\nPlease collect all the alteres!", 2);
}