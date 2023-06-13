/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:30:48 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/13 16:48:42 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	display_move_count(t_game *game)
{
	char	*move;

	move = ft_itoa (game->move_count);
	mlx_put_image_to_window (game->graph.mlx, game->graph.win, \
		game->graph.img_wall, 0, 0);
	if (game->move_count > 0)
	{
		mlx_string_put(game->graph.mlx, game->graph.win, \
			50, 50, 0x00FF0000, "Move done:");
		mlx_string_put(game->graph.mlx, game->graph.win, \
			50, 65, 0x00FF0000, move);
		free(move);
		move = NULL;
	}
	else
	{
		free(move);
		return ;
	}
}

void	display_ammo(t_game *game)
{
	char	*ammo;

	ammo = ft_itoa(game->ammo_count);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win, \
		game->graph.img_wall, 128, 0);
	if (game->ammo_count > 0)
	{
		mlx_string_put(game->graph.mlx, game->graph.win, \
			178, 50, 0x00FF0000, "Ammo:");
		mlx_string_put(game->graph.mlx, game->graph.win, \
			178, 65, 0x00FF0000, ammo);
		free(ammo);
		ammo = NULL;
	}
	else
	{
		free(ammo);
		return ;
	}
}

int	monster_animation(t_game *game)
{
	game->monster_animation_timer += FRAMERATE;
	if (game->monster_animation_timer >= ANIMATIONDELAY)
	{
		if (game->monster_frame == 1)
			game->monster_frame = 2;
		else
			game->monster_frame = 1;
		game->monster_animation_timer = 0;
	}
	place_image(game);
	return (0);
}
