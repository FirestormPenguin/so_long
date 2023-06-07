/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:04:37 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/07 18:24:01 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void exit_game(t_game *game)
{
    close_win(&game->graph);
}

void direction_W(int id, t_game *game)
{
    if (id == W)
        if (game->vars->map[game->map_i - 1][game->map_j] != '1')
        {
            if (game->vars->map[game->map_i - 1][game->map_j] == 'C')
                game->vars->index_collect--;
            if (game->vars->map[game->map_i - 1][game->map_j] == 'E' && game->vars->index_collect <= 0)
                exit_game(game);
            else if (game->vars->map[game->map_i - 1][game->map_j] == 'E' && game->vars->index_collect > 0)
                return ;
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i - 1][game->map_j] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow, game->y_arrow - TILESIZE);
            game->move_count++;
            ft_printf("Move done: %d\n", game->move_count);
        }
}

void    direction_S(int id, t_game *game)
{
    if (id == S)
        if (game->vars->map[game->map_i + 1][game->map_j] != '1')
        {
            if (game->vars->map[game->map_i + 1][game->map_j] == 'C')
                game->vars->index_collect -= 1;
            if (game->vars->map[game->map_i + 1][game->map_j] == 'E' && game->vars->index_collect <= 0)
                exit_game(game);
            else if (game->vars->map[game->map_i + 1][game->map_j] == 'E' && game->vars->index_collect > 0)
                return ;
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i + 1][game->map_j] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow, game->y_arrow + TILESIZE);
            game->move_count++;
            ft_printf("Move done: %d\n", game->move_count);
        }
}

void direction_A(int id, t_game *game)
{
    if (id == A)
        if (game->vars->map[game->map_i][game->map_j - 1] != '1')
        {
            if (game->vars->map[game->map_i][game->map_j - 1] == 'C')
                game->vars->index_collect--;
            if (game->vars->map[game->map_i][game->map_j - 1] == 'E' && game->vars->index_collect <= 0)
                exit_game(game);
            else if (game->vars->map[game->map_i][game->map_j - 1] == 'E' && game->vars->index_collect > 0)
                return ;
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i][game->map_j - 1] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow - TILESIZE, game->y_arrow);
            game->move_count++;
            ft_printf("Move done: %d\n", game->move_count);
        }
}

void direction_D(int id, t_game *game)
{
    if (id == D)
        if (game->vars->map[game->map_i][game->map_j + 1] != '1')
        {
            if (game->vars->map[game->map_i][game->map_j + 1] == 'C')
                game->vars->index_collect--;
            if (game->vars->map[game->map_i][game->map_j + 1] == 'E' && game->vars->index_collect <= 0)
                exit_game(game);
            else if (game->vars->map[game->map_i][game->map_j + 1] == 'E' && game->vars->index_collect > 0)
                return ;
            game->vars->map[game->map_i][game->map_j] = '0';
            game->vars->map[game->map_i][game->map_j + 1] = 'P';
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_terrain, game->x_arrow, game->y_arrow);
            mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_player, game->x_arrow + TILESIZE, game->y_arrow);
            game->move_count++;
            ft_printf("Move done: %d\n", game->move_count);
        }
}
