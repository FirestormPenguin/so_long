/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:09:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 21:37:25 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char *path;
	t_vars *vars;
	t_graph graph;
	t_move move;

	vars = (t_vars *)malloc (sizeof (t_vars));
	if (ac != 2)
		return (printf("no vars\n"), 0);
	path = av[1];
	get_map(path, vars);
	mlx_manage(graph, vars, move);
}
