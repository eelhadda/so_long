/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:14:33 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/21 16:49:09 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(void)
{
	ft_putstr_fd(RED"Error : empty or invalid map !\n", 2);
	exit (1);
}

char	**map_reader(char *path)
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
		error_map();
	mapholder = ft_split(map, '\n');
	free(map);
	return (mapholder);
}
