/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:54:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/06 17:40:27 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	close_win(t_graph *graph)
{
	mlx_destroy_window(graph->mlx, graph->win);
    free(graph->mlx);
	ft_printf("Exit\n");
	exit(0);
}

void mlx_manage(t_game *game)
{
    int img_width;
	int img_height;
    
    game->x = (game->vars->column * TILESIZE);
    game->y = (game->vars->line * TILESIZE);
    
    game->graph.mlx = mlx_init();
    game->graph.win = mlx_new_window(game->graph.mlx, game->x, game->y, "Finestra!!");
    game->graph.img_terrain = mlx_xpm_file_to_image(game->graph.mlx, TERRAIN, &img_width, &img_height);
    game->graph.img_wall = mlx_xpm_file_to_image(game->graph.mlx, WALL, &img_width, &img_height);
    game->graph.img_player = mlx_xpm_file_to_image(game->graph.mlx, PLAYER, &img_width, &img_height);
    game->graph.img_collect = mlx_xpm_file_to_image(game->graph.mlx, COLLECT, &img_width, &img_height);
    game->graph.img_exit = mlx_xpm_file_to_image(game->graph.mlx,EXIT, &img_width, &img_height);
    place_image(game);
    mlx_hook(game->graph.win, 17, 1L << 17, close_win, &game->graph);
    mlx_key_hook(game->graph.win, &hook_manage, game);
    mlx_loop(game->graph.mlx);
}
