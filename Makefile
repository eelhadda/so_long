# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 14:09:11 by eelhadda          #+#    #+#              #
#    Updated: 2023/08/25 16:46:21 by eelhadda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I headers/
SRCS = free.c coords.c composents.c map_checker.c map_format.c map_reader.c libft/ft_strjoin.c  libft/ft_strlen.c \
		libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strcmp.c libft/ft_strrchr.c libft/ft_putnbr.c  \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c key_hooks.c \
		moves.c path_checkers.c player_moves.c textures.c so_long.c winning.c checking_map_walls.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all