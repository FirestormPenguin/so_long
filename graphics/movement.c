/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/05 18:23:32 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void move_up(t_game *game)
{
    game->vars->map[0][0] = 0;
    // int i;
    // int j;
    // int map_i;
    // int map_j;

    // i = 0;
    // map_i = 0;
    // while (i < game->vars->line * 128)
    // {
    //     j = 0;
    //     map_j = 0;
    //     while (j < game->vars->column * 128)
    //     {
    //         if (game->vars->map[map_i][map_j] == 'P')
    //         {
    //             game->vars->map[map_i][map_j] = '0';
    //         }
    //         j += 128;
    //         map_j++;
    //     }
    //     i += 128;
    //     map_i++;
    // }
}

int player_move(int keycode, t_game *game)
{
    if (keycode == W)
        move_up(game);
    if (keycode == A)
        ft_printf("left\n");
    else if (keycode == D)
        ft_printf ("right\n");
    else if (keycode == S)
        ft_printf("down\n");
    return (0);
}

void    movement(t_game *game)
{
    mlx_key_hook(game->graph.win, &player_move, &game);
}
