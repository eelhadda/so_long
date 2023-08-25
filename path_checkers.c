/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:19:31 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/21 16:48:23 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *mapc)
{
	if ((map[x][y] != 'P' && map[x][y] != '0' && map[x][y] != 'C')
		|| (x < 0 || y < 0 || x >= mapc[0] || y >= mapc[1]))
		return ;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y, mapc);
	flood_fill(map, x - 1, y, mapc);
	flood_fill(map, x, y + 1, mapc);
	flood_fill(map, x, y - 1, mapc);
}

int	exit_checker(char **map, int x, int y)
{
	if (map[x + 1][y] == 'F' || map[x - 1][y] == 'F'
		|| map[x][y + 1] == 'F' || map[x][y - 1] == 'F')
		return (1);
	else
		return (0);
}

int	path_checker(char *path)
{
	char	**map;
	int		p[2];
	int		mapc[2];
	int		exitc[2];

	map = map_reader(path);
	element_coordinates(map, p, 'P');
	element_coordinates(map, exitc, 'E');
	mapc[0] = map_y(map);
	mapc[1] = map_x(map);
	flood_fill(map, p[0], p[1], mapc);
	if ((elements_counter(map, 'C') != 0)
		|| (exit_checker(map, exitc[0], exitc[1]) == 0))
	{
		map_free(map);
		return (0);
	}
	else
	{
		map_free(map);
		return (1);
	}
}
