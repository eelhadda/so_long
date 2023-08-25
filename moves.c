/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:16:17 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/25 19:04:47 by eelhadda         ###   ########.fr       */
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
