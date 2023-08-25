/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:19:55 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/22 18:24:55 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	if (map[y - 1][x] == '0')
		move_up(game);
	if (map[y - 1][x] == 'C')
	{
		move_up(game);
		game->map->c--;
	}
	if (map[y - 1][x] == 'E')
		winning(game);
}

void	player_move_down(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	if (map[y + 1][x] == '0')
		move_down(game);
	if (map[y + 1][x] == 'C')
	{
		move_down(game);
		game->map->c--;
	}
	if (map[y + 1][x] == 'E')
		winning(game);
}

void	player_move_left(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	if (map[y][x - 1] == '0')
		move_left(game);
	if (map[y][x - 1] == 'C')
	{
		move_left(game);
		game->map->c--;
	}
	if (map[y][x - 1] == 'E')
		winning(game);
}

void	player_move_right(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map->map;
	x = game->map->player->x;
	y = game->map->player->y;
	if (map[y][x + 1] == '0')
		move_right(game);
	if (map[y][x + 1] == 'C')
	{
		move_right(game);
		game->map->c--;
	}
	if (map[y][x + 1] == 'E')
		winning(game);
}
