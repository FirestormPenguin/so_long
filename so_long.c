/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:09:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/05 17:37:11 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char *path;
	t_game *game;

	game = (t_game *)malloc (sizeof (t_game));
	game->vars = (t_vars *)malloc (sizeof (t_vars));
	if (ac != 2)
		return (printf("no vars\n"), 0);
	path = av[1];
	get_map(path, game);
	mlx_manage(game);
}
