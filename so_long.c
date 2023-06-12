/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:09:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/12 17:47:40 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->vars->line = 0;
	game->vars->column = 0;
	game->vars->player = 0;
	game->vars->index_collect = 0;
	game->vars->exit = 0;
	game->x = 0;
	game->y = 0;
	game->map_i = 0;
	game->map_j = 0;
	game->x_arrow = 0;
	game->y_arrow = 0;
	game->move_count = 0;
	game->ammo_count = 0;
	game->monster_animation_timer = 0;
	game->monster_frame = 0;
}

int	main(int ac, char **av)
{
	char	*path;
	t_game	*game;

	game = (t_game *)malloc (sizeof (t_game));
	game->vars = (t_vars *)malloc (sizeof (t_vars));
	if (ac != 2)
		return (printf("no vars\n"), 0);
	path = av[1];
	init_struct(game);
	get_map(path, game);
	mlx_manage(game);
}
