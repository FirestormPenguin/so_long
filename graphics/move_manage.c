/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:04:37 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/10 18:26:31 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	exit_game(t_game *game, int id)
{
	if (id == 1)
		close_winning(&game->graph);
	else if (id == 2)
		close_losing(&game->graph);
}

void	direction_w(t_game *game)
{
	if (game->vars->map[game->map_i - 1][game->map_j] != '1')
	{
		if (game->vars->map[game->map_i - 1][game->map_j] == 'C')
			game->vars->index_collect--;
		else if (game->vars->map[game->map_i - 1][game->map_j] == 'E'
				&& game->vars->index_collect <= 0)
			exit_game(game, 1);
		else if (game->vars->map[game->map_i - 1][game->map_j] == 'E'
				&& game->vars->index_collect > 0)
			return ;
		else if (game->vars->map[game->map_i - 1][game->map_j] == 'M'
				&& game->ammo_count <= 0)
			exit_game(game, 2);
		else if (game->vars->map[game->map_i - 1][game->map_j] == 'M'
				&& game->ammo_count > 0)
			game->ammo_count -= 1;
		else if (game->vars->map[game->map_i - 1][game->map_j] == 'A')
			game->ammo_count += 1;
		game->vars->map[game->map_i][game->map_j] = '0';
		game->vars->map[game->map_i - 1][game->map_j] = 'P';
		place_w(game);
	}
}

void	direction_s(t_game *game)
{
	if (game->vars->map[game->map_i + 1][game->map_j] != '1')
	{
		if (game->vars->map[game->map_i + 1][game->map_j] == 'C')
			game->vars->index_collect -= 1;
		else if (game->vars->map[game->map_i + 1][game->map_j] == 'E'
				&& game->vars->index_collect <= 0)
			exit_game(game, 1);
		else if (game->vars->map[game->map_i + 1][game->map_j] == 'E'
				&& game->vars->index_collect > 0)
			return ;
		else if (game->vars->map[game->map_i + 1][game->map_j] == 'M'
				&& game->ammo_count <= 0)
			exit_game(game, 2);
		else if (game->vars->map[game->map_i + 1][game->map_j] == 'M'
				&& game->ammo_count > 0)
			game->ammo_count -= 1;
		else if (game->vars->map[game->map_i + 1][game->map_j] == 'A')
			game->ammo_count += 1;
		game->vars->map[game->map_i][game->map_j] = '0';
		game->vars->map[game->map_i + 1][game->map_j] = 'P';
		place_s(game);
	}
}

void	direction_a(t_game *game)
{
	if (game->vars->map[game->map_i][game->map_j - 1] != '1')
	{
		if (game->vars->map[game->map_i][game->map_j - 1] == 'C')
			game->vars->index_collect--;
		else if (game->vars->map[game->map_i][game->map_j - 1] == 'E'
				&& game->vars->index_collect <= 0)
			exit_game(game, 1);
		else if (game->vars->map[game->map_i][game->map_j - 1] == 'E'
				&& game->vars->index_collect > 0)
			return ;
		else if (game->vars->map[game->map_i][game->map_j - 1] == 'M'
				&& game->ammo_count <= 0)
			exit_game(game, 2);
		else if (game->vars->map[game->map_i][game->map_j - 1] == 'M'
				&& game->ammo_count > 0)
			game->ammo_count -= 1;
		else if (game->vars->map[game->map_i][game->map_j - 1] == 'A')
			game->ammo_count += 1;
		game->vars->map[game->map_i][game->map_j] = '0';
		game->vars->map[game->map_i][game->map_j - 1] = 'P';
		place_a(game);
	}
}

void	direction_d(t_game *game)
{
	if (game->vars->map[game->map_i][game->map_j + 1] != '1')
	{
		if (game->vars->map[game->map_i][game->map_j + 1] == 'C')
			game->vars->index_collect--;
		else if (game->vars->map[game->map_i][game->map_j + 1] == 'E'
				&& game->vars->index_collect <= 0)
			exit_game(game, 1);
		else if (game->vars->map[game->map_i][game->map_j + 1] == 'E'
				&& game->vars->index_collect > 0)
			return ;
		else if (game->vars->map[game->map_i][game->map_j + 1] == 'M'
				&& game->ammo_count <= 0)
			exit_game(game, 2);
		else if (game->vars->map[game->map_i][game->map_j + 1] == 'M'
				&& game->ammo_count > 0)
			game->ammo_count -= 1;
		else if (game->vars->map[game->map_i][game->map_j + 1] == 'A')
			game->ammo_count += 1;
		game->vars->map[game->map_i][game->map_j] = '0';
		game->vars->map[game->map_i][game->map_j + 1] = 'P';
		place_d(game);
	}
}
