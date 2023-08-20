# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 17:56:44 by ael-balb          #+#    #+#              #
#    Updated: 2023/08/19 16:35:40 by ael-balb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I headers/
SRCS = ./get_next_line/get_next_line.c\
       ./get_next_line/get_next_line_utils.c\
	   ./libft/ft_putnbr.c\
	   ./libft/ft_putstr_fd.c\
	   ./libft/ft_split.c\
	   ./libft/ft_strcmp.c\
	   so_long.c\
	   free.c\
	   ft_checking_map.c\
	   ft_elements.c\
	   ft_format_map.c\
	   ft_key_hooks.c\
	   ft_locations.c\
	   ft_moves_player.c\
	   ft_moves.c\
	   ft_reading_map.c\
	   ft_show_textures.c\
	   ft_strrchr.c\
	   ft_valid_path.c\
	   ft_wall_checker.c\
	   gagner.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all