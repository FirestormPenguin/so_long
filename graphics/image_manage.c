/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:25:45 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/10 03:33:42 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	put_monster_image(t_game *game)
{
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.img_monster, game->x_arrow, game->y_arrow);
	if (game->monster_frame == 1)
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_monster, game->x_arrow, game->y_arrow);
	else if (game->monster_frame == 2)
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_monster2, game->x_arrow, game->y_arrow);
}

void	put_correct_image(t_game *game)
{
	if (game->vars->map[game->map_i][game->map_j] == '1')
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_wall, game->x_arrow, game->y_arrow);
	else if (game->vars->map[game->map_i][game->map_j] == 'P')
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_player, game->x_arrow, game->y_arrow);
	else if (game->vars->map[game->map_i][game->map_j] == 'C')
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_collect, game->x_arrow, game->y_arrow);
	else if (game->vars->map[game->map_i][game->map_j] == 'E')
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_exit, game->x_arrow, game->y_arrow);
	else if (game->vars->map[game->map_i][game->map_j] == 'M')
	{
		put_monster_image(game);
	}
	else if (game->vars->map[game->map_i][game->map_j] == 'A')
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_ammo, game->x_arrow, game->y_arrow);
	else
		mlx_put_image_to_window(game->graph.mlx, game->graph.win,
			game->graph.img_terrain, game->x_arrow, game->y_arrow);
	display_move_count(game);
	display_ammo(game);
}

void	place_image(t_game *game)
{
	game->y_arrow = 0;
	game->map_i = 0;
	while (game->y_arrow < game->y)
	{
		game->x_arrow = 0;
		game->map_j = 0;
		while (game->x_arrow < game->x)
		{
			put_correct_image(game);
			game->x_arrow += TILESIZE;
			game->map_j++;
		}
		game->y_arrow += TILESIZE;
		game->map_i++;
	}
}
