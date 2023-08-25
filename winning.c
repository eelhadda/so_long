/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhadda <eelhadda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:21:24 by eelhadda          #+#    #+#             */
/*   Updated: 2023/08/25 19:15:13 by eelhadda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	winning(t_game *game)
{
	if (game->map->c == 0)
	{
		ft_putstr_fd(GREEN"\nWP CONGRATS U WIN !\n", 1);
		exit(0);
	}
	ft_putstr_fd(RED"\nU need to collect all humans souls !", 2);
}
