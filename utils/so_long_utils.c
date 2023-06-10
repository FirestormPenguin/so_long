/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:39 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/10 20:12:12 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	free_vars(t_game *game)
{
	int	i;

	i = 0;
	while (game->vars->map[i])
	{
		free(game->vars->map[i]);
		i++;
	}
	free(game->vars->map);
	free(game->vars);
	free_graph(&game->graph);
	free(game);
}

void	free_graph(t_graph *graph)
{
	free(graph->img_terrain);
	free(graph->img_wall);
	free(graph->img_player);
	free(graph->img_collect);
	free(graph->img_exit);
	free(graph->img_monster);
	free(graph->img_monster2);
	free(graph->img_ammo);
}
