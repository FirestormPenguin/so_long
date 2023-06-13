/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:39 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/13 17:00:16 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void	free_vars(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->vars->line)
	{
		free(game->vars->map[i]);
		game->vars->map[i] = NULL;
		i++;
	}
	free(game->vars->map);
	free(game->vars);
	free(game);
}
