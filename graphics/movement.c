/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 20:11:01 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void    player_move(t_vars *vars)
{
    
}

void    movement(t_graph graph, t_vars *vars)
{
    mlx_key_hook(graph.win, player_move, &vars);
}
