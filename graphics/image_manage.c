/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:25:45 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/06 15:57:24 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void    put_correct_image(t_game *game, int i, int j, int map_i, int map_j)
{
    if (game->vars->map[map_i][map_j] == '1')
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_wall, j, i);
    else if(game->vars->map[map_i][map_j] == 'P')
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, j, i);
    else if(game->vars->map[map_i][map_j] == 'C')
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_collect, j, i);
    else if(game->vars->map[map_i][map_j] == 'E')
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_exit, j, i);
    else 
        mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, j, i);
}

void place_image(t_game *game)
{
    int i;
    int j;
    int map_i;
    int map_j;

    i = 0;
    map_i = 0;
    while (i < game->y)
    {
        j = 0;
        map_j = 0;
        while (j < game->x)
        {
            put_correct_image(game, i , j, map_i, map_j);
            j += TILESIZE;
            map_j++;
        }
        i += TILESIZE;
        map_i++;
    }
}
