/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:30:48 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/09 15:48:16 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void display_move_count(t_game *game)
{
    char    *move;

    move = ft_itoa(game->move_count);
    mlx_string_put(game->graph.mlx, game->graph.win, 50, 50, 0x00FF0000, move);
}
