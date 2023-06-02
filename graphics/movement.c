/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 21:40:52 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int player_move(t_move move)
{
    if (move.direction == W)
        ft_printf("up\n");
    else if (move.direction == A)
        ft_printf("left\n");
    else if (move.direction == D)
        ft_printf ("right\n");
    else if (move.direction == S)
        ft_printf("down\n");
    return (0);
}

void    movement(t_graph graph, t_move move)
{
    move.direction = mlx_key_hook(graph.win, &player_move, &move);
}
