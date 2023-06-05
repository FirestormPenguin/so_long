/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:54:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/05 18:18:11 by egiubell         ###   ########.fr       */
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
    int x;
    int y;
    
    x = game->vars->column * 128;
    y = game->vars->line * 128;
    
    game->graph.mlx = mlx_init();
    game->graph.win = mlx_new_window(game->graph.mlx, x, y, "Finestra!!");
    game->graph.img_terrain = mlx_xpm_file_to_image(game->graph.mlx, TERRAIN, &img_width, &img_height);
    game->graph.img_wall = mlx_xpm_file_to_image(game->graph.mlx, WALL, &img_width, &img_height);
    game->graph.img_player = mlx_xpm_file_to_image(game->graph.mlx, PLAYER, &img_width, &img_height);
    game->graph.img_collect = mlx_xpm_file_to_image(game->graph.mlx, COLLECT, &img_width, &img_height);
    game->graph.img_exit = mlx_xpm_file_to_image(game->graph.mlx,EXIT, &img_width, &img_height);
    place_image(game, x, y);
    movement(game);
    mlx_hook(game->graph.win, 17, 1L << 17, close_win, &game->graph);
    mlx_loop(game->graph.mlx);
}
