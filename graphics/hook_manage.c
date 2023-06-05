/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:06:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/05 19:26:42 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

int hook_manage(int keycode, t_game *game)
{
    if (keycode == ESC)
        close_esc(&game->graph);
    if (keycode == W)
        ft_printf("up\n");
    else if (keycode == A)
        ft_printf("left\n");
    else if (keycode == D)
        ft_printf ("right\n");
    else if (keycode == S)
        ft_printf("down\n");
    return (0);
}
