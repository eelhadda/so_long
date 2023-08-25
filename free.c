/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:22:04 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/25 19:15:22 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	game_free(void *alias)
{
	t_game	*game;

	game = (t_game *)alias;
	free(game->map->player);
	free(game->map->map);
	free(game->map);
	free(game);
	exit(0);
	return (1);
}
