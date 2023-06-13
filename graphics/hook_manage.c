/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/13 16:53:20 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	move_select(int id, t_game *game)
{
	if (id == W)
		direction_w(game);
	else if (id == S)
		direction_s(game);
	else if (id == A)
		direction_a(game);
	else if (id == D)
		direction_d(game);
}

void	move(int id, t_game *game)
{
	game->y_arrow = 0;
	game->map_i = 0;
	while (game->y_arrow < game->y)
	{
		game->x_arrow = 0;
		game->map_j = 0;
		while (game->x_arrow < game->x)
		{
			if (game->vars->map[game->map_i][game->map_j] == 'P')
			{
				move_select(id, game);
				return ;
			}
			game->x_arrow += TILESIZE;
			game->map_j++;
		}
		game->y_arrow += TILESIZE;
		game->map_i++;
	}
}

int	hook_manage(int keycode, t_game *game)
{
	if (keycode == ESC)
		pressed_x(game);
	if (keycode == W || keycode == A || keycode == D || keycode == S)
	{
		move(keycode, game);
		display_move_count(game);
		display_ammo(game);
	}
	return (0);
}
