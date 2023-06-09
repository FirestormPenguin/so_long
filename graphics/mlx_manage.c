/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:54:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/16 22:46:16 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	init_img(t_game *game)
{
	int	img_width;
	int	img_height;

	game->graph.img_terrain = mlx_xpm_file_to_image(game->graph.mlx, \
	TERRAIN, &img_width, &img_height);
	game->graph.img_wall = mlx_xpm_file_to_image(game->graph.mlx, \
	WALL, &img_width, &img_height);
	game->graph.img_player = mlx_xpm_file_to_image(game->graph.mlx, \
	PLAYER, &img_width, &img_height);
	game->graph.img_player2 = mlx_xpm_file_to_image(game->graph.mlx, \
	PLAYER2, &img_width, &img_height);
	game->graph.img_collect = mlx_xpm_file_to_image(game->graph.mlx, \
	COLLECT, &img_width, &img_height);
	game->graph.img_exit = mlx_xpm_file_to_image(game->graph.mlx, \
	EXIT, &img_width, &img_height);
	game->graph.img_monster = mlx_xpm_file_to_image(game->graph.mlx, \
	MONSTER, &img_width, &img_height);
	game->graph.img_monster2 = mlx_xpm_file_to_image(game->graph.mlx, \
	MONSTER2, &img_width, &img_height);
	game->graph.img_ammo = mlx_xpm_file_to_image(game->graph.mlx, \
	AMMO, &img_width, &img_height);
}

void	mlx_manage(t_game *game)
{
	game->x = (game->vars->column * TILESIZE);
	game->y = (game->vars->line * TILESIZE);
	game->move_count = 0;
	game->ammo_count = 0;
	game->graph.mlx = mlx_init();
	game->graph.win = mlx_new_window(game->graph.mlx, \
		game->x, game->y, "Finestra!!");
	init_img(game);
	place_image(game);
	mlx_key_hook(game->graph.win, &hook_manage, game);
	mlx_hook(game->graph.win, 17, 1L << 17, pressed_x, game);
	mlx_loop_hook(game->graph.mlx, monster_animation, game);
	mlx_loop(game->graph.mlx);
}
