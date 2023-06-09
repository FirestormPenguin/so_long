/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:30:48 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/09 16:37:59 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void display_move_count(t_game *game)
{
    char    *move;

    move = ft_itoa(game->move_count);
    mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_wall, 0, 0);
    mlx_string_put(game->graph.mlx, game->graph.win, 50, 50, 0x00FF0000, "Move done:");
    mlx_string_put(game->graph.mlx, game->graph.win, 50, 65, 0x00FF0000, move);
}

void pick_ammo(t_game *game)
{
    char    *ammo;
    
    game->ammo_count += 1;
    ammo = ft_itoa(game->ammo_count);
    mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.img_wall, 128, 0);
    mlx_string_put(game->graph.mlx, game->graph.win, 178, 50, 0x00FF0000, "Ammo:");
    mlx_string_put(game->graph.mlx, game->graph.win, 178, 65, 0x00FF0000, ammo);
}