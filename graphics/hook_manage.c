/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/05 19:40:21 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void move(int id, t_game *game)
{
    int i;
    int j;
    int map_i;
    int map_j;

    i = 0;
    map_i = 0;
    while (i < game->vars->line * 128)
    {
        j = 0;
        map_j = 0;
        while (j < game->vars->column * 128)
        {
            if (game->vars->map[map_i][map_j] == 'P' && id == W)
            {
                game->vars->map[map_i][map_j] = '0';
                mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, j, i);
                mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, j, i - 128);
            }
            j += 128;
            map_j++;
        }
        i += 128;
        map_i++;
    }
}

int hook_manage(int keycode, t_game *game)
{
    if (keycode == ESC)
        close_esc(&game->graph);
    if (keycode == W)
        move(keycode, game);
    else if (keycode == A)
        move(keycode, game);
    else if (keycode == D)
        move(keycode, game);
    else if (keycode == S)
        move(keycode, game);
    return (0);
}
