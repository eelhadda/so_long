/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:14:10 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/25 19:16:06 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "/nfs/homes/eelhadda/Documents/minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

# define RED    "\033[1m\033[31m"
# define GREEN    "\033[1m\033[32m"
# define YELLOW    "\033[1m\033[33m"

typedef struct s_coords
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_map
{
	char			**map;
	int				x;
	int				y;
	int				c;
	t_xy			*player;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*img;
	int		win_size;
	int		counter;
	t_map	*map;
}	t_game;

void	map_free(char **map);
int		game_free(void *alias);

int		map_x(char **map);
int		map_y(char **map);
void	element_coordinates(char **map, int *coo, char c);
t_xy	*element_placement(char **map, char c);

int		elements_check(char **map);
int		elements_counter(char **map, char c);
int		elements_verification(char **map);

char	**map_checker(char *map_path);

int		extension_checker(char *ext);
int		format_checker(char **map);

char	**map_read(char *path);

int		upper_walls(char **map);
int		bottom_walls(char **map);
int		right_walls(char **map);
int		left_walls(char **map);

void	ft_putnbr(int nb);

void	ft_putstr_fd(char *str, int fd);

char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);

int		ft_strcmp(const char *str1, const char *str2);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strrchr(const char *s, int c);

int		key_hook(int key, t_game *game);

void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

int		path_checker(char *path);

char	**map_reader(char *path);

void	player_move_up(t_game *game);
void	player_move_down(t_game *game);
void	player_move_left(t_game *game);
void	player_move_right(t_game *game);

void	apply_textures(t_game *game);

t_map	*map_initialiser(char *path);

void	winning(t_game *game);

#endif