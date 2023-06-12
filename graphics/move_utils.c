/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:54:09 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/12 15:57:46 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	place_w(t_game *game)
{
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_terrain, game->x_arrow, game->y_arrow);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_player, game->x_arrow,
		game->y_arrow - TILESIZE);
	game->move_count++;
	ft_printf ("Move done: %d\n", game->move_count);
}

void	place_s(t_game *game)
{
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_terrain, game->x_arrow, game->y_arrow);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_player, game->x_arrow,
		game->y_arrow + TILESIZE);
	game->move_count++;
	printf ("Move done: %d\n", game->move_count);
}

void	place_a(t_game *game)
{
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_terrain, game->x_arrow, game->y_arrow);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_player, game->x_arrow - TILESIZE,
		game->y_arrow);
	game->move_count++;
	printf ("Move done: %d\n", game->move_count);
}

void	place_d(t_game *game)
{
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_terrain, game->x_arrow, game->y_arrow);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_player, game->x_arrow + TILESIZE,
		game->y_arrow);
	game->move_count++;
	printf ("Move done: %d\n", game->move_count);
}
