/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:25:45 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 19:33:16 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

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
