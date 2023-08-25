/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:39:49 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/20 20:57:23 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_x(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	map_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	element_coordinates(char **map, int *coo, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				coo[0] = i;
				coo[1] = j;
			}
			j++;
		}
		i++;
	}
}

t_xy	*element_placement(char **map, char c)
{
	t_xy	*player;
	int		i;
	int		j;

	i = 0;
	player = malloc(sizeof(t_xy));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				player->y = i;
				player->x = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
