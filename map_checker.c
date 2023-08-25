/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:14:07 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/21 16:50:57 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(char **map)
{
	if (!format_checker(map) || !elements_verification(map))
		return (0);
	return (1);
}

char	**map_checker(char *path)
{
	char	**map;

	map = map_reader(path);
	if (!map || !valid_map(map))
		exit (1);
	if (path_checker(path) == 0)
	{
		ft_putstr_fd(RED
			"Error : Jacke can't exit or can't eat all the burgers :(\n", 2);
		exit (1);
	}
	return (map);
}
