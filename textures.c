/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:20:37 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/22 20:55:05 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture(t_game *game, int x, int y)
{
	char	*path;

	if (game->map->map[x][y] == 'E')
		path = "textures/Ex.xpm";
	else if (game->map->map[x][y] == '1')
		path = "textures/wall.xpm";
	else if (game->map->map[x][y] == '0')
		path = "textures/floor.xpm";
	else if (game->map->map[x][y] == 'C')
		path = "textures/Coll.xpm";
	else if (game->map->map[x][y] == 'P')
		path = "textures/P.xpm";
	else
		return ;
	game->img = mlx_xpm_file_to_image (game->mlx, path,
			&game->win_size, &game->win_size);
	if (!game->img)
	{
		ft_putstr_fd(RED"Error : texture not found !\n", 2);
		exit(1);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img, y * 50, x * 50);
	mlx_destroy_image(game->mlx, game->img);
}

void	apply_textures(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map->map[x])
	{
		y = 0;
		while (game->map->map[x][y] != '\n' && game->map->map[x][y])
		{
			texture(game, x, y);
			y++;
		}
		x++;
	}
}
