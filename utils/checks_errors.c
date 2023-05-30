/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:19:36 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 18:26:17 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void error(t_vars *vars)
{
	printf("Error\n");
	free_vars(vars);
	exit(0);
}

int checks_vars(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < vars->line)
	{
		j= 0;
		while (j < vars->column)
		{
			if (vars->map[i][j] == 'P')
				vars->player++;
			else if (vars->map[i][j] == 'C')
				vars->collect++;
			if (vars->map[i][j] == 'E')
				vars->exit++;
			j++;
		}
		i++;
	}
	if (vars->player < 1 || vars-> collect < 1 || vars->exit < 1 ||
		vars->player > 1 || vars-> exit > 1)
		return (1);
	return (0);
}

void check_errors(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < vars->line)
	{
		j= 0;
		while (j < vars->column)
		{
			if ((vars->map[0][j] != '1' || vars->map[vars->line - 1][j] != '1') || 
				(vars->map[i][0] != '1' || vars->map[i][vars->column - 1] != '1'))
					error(vars);
			if (vars->map[i][j] != '0' && vars->map[i][j] != '1' && vars->map[i][j] != 'C' && 
				vars->map[i][j] != 'E' && vars->map[i][j] != 'P')
					error(vars);
			j++;
		}
		i++;
	}
	if (checks_vars(vars) == 1)
		error(vars);
}
