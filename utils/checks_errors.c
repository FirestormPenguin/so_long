/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:19:36 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 18:50:10 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void error(t_vars *vars, int id)
{
	printf("Error\n");
	if (id == 1)
		printf("Edges not valid\n");
	else if (id == 2)
		printf("Found invalid character\n");
	else if (id == 3)
		printf("Number of variables invalid\n");
	else if (id == 4)
		printf("Lines/Columns format invalid\n");
	free_vars(vars);
	exit(0);
}

int	checks_format(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			j++;
		}
		if (j != vars->column + 1)		//con +1 in 42, +2 a casa, da capire
			return (1);
		i++;
	}
	return (0);
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
					error(vars, 1);
			if (vars->map[i][j] != '0' && vars->map[i][j] != '1' && vars->map[i][j] != 'C' && 
				vars->map[i][j] != 'E' && vars->map[i][j] != 'P')
					error(vars, 2);
			j++;
		}
		i++;
	}
	if (checks_vars(vars) == 1)
		error(vars, 3);
	if (checks_format(vars) == 1)
		error(vars, 4);
}
