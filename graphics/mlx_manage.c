/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:54:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 20:05:35 by egiubell         ###   ########.fr       */
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

void mlx_manage(t_graph graph, t_vars *vars)
{
    int img_width;
	int img_height;
    int x;
    int y;
    
    x = vars->column * 128;
    y = vars->line * 128;
    
    graph.mlx = mlx_init();
    graph.win = mlx_new_window(graph.mlx, x, y, "Finestra!!");
    graph.img_terrain = mlx_xpm_file_to_image(graph.mlx, TERRAIN, &img_width, &img_height);
    graph.img_wall = mlx_xpm_file_to_image(graph.mlx, WALL, &img_width, &img_height);
    graph.img_player = mlx_xpm_file_to_image(graph.mlx, PLAYER, &img_width, &img_height);
    graph.img_collect = mlx_xpm_file_to_image(graph.mlx, COLLECT, &img_width, &img_height);
    graph.img_exit = mlx_xpm_file_to_image(graph.mlx,EXIT, &img_width, &img_height);
    place_image(graph, vars, x, y);
    mlx_hook(graph.win, 17, 1L << 17, close_win, &graph);
    mlx_loop(graph.mlx);
}
