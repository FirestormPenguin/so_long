/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:54:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 19:23:49 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int	close_win(t_graph *graph)
{
	mlx_destroy_window(graph->mlx, graph->win);
    free(graph->mlx);
	printf("Exit\n");
	exit(0);
}

void    put_correct_image(t_graph graph, t_vars *vars, int i, int j, int map_i, int map_j)
{
    if (vars->map[map_i][map_j] == '1')
        mlx_put_image_to_window(graph.mlx, graph.win, graph.img_wall, j, i);
    else if(vars->map[map_i][map_j] == 'P')
        mlx_put_image_to_window(graph.mlx, graph.win, graph.img_player, j, i);
    else if(vars->map[map_i][map_j] == 'C')
        mlx_put_image_to_window(graph.mlx, graph.win, graph.img_collect, j, i);
    else if(vars->map[map_i][map_j] == 'E')
        mlx_put_image_to_window(graph.mlx, graph.win, graph.img_exit, j, i);
    else 
        mlx_put_image_to_window(graph.mlx, graph.win, graph.img_terrain, j, i);
}

void place_image(t_graph graph, t_vars *vars, int x, int y)
{
    int i;
    int j;
    int map_i;
    int map_j;

    i = 0;
    map_i = 0;
    while (i < y)
    {
        j = 0;
        map_j = 0;
        while (j < x)
        {
            put_correct_image(graph, vars, i , j, map_i, map_j);
            j += 128;
            map_j++;
        }
        i += 128;
        map_i++;
    }
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
