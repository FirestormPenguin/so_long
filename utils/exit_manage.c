/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:58:19 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/13 18:14:06 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	close_generic(t_graph *graph)
{
	mlx_destroy_image(graph->mlx, graph->img_terrain);
	mlx_destroy_image(graph->mlx, graph->img_wall);
	mlx_destroy_image(graph->mlx, graph->img_player);
	mlx_destroy_image(graph->mlx, graph->img_exit);
	mlx_destroy_image(graph->mlx, graph->img_collect);
	mlx_destroy_image(graph->mlx, graph->img_monster);
	mlx_destroy_image(graph->mlx, graph->img_monster2);
	mlx_destroy_image(graph->mlx, graph->img_ammo);
	mlx_destroy_window(graph->mlx, graph->win);
}

int	close_winning(t_game *game)
{
	close_generic(&game->graph);
	free_vars(game);
	ft_printf("YOU WIN!\n");
	exit(0);
}

int	close_losing(t_game *game)
{
	close_generic(&game->graph);
	free_vars(game);
	ft_printf("YOU LOSE!\n");
	exit(0);
}

int	pressed_x(t_game *game)
{
	close_generic(&game->graph);
	free_vars(game);
	ft_printf("Game closed\n");
	exit(0);
}
