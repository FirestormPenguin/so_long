/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 18:09:49 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_column(char *path)
{
	int i;
	char *str;
	int fd;
		
	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	free(str);
	while (str[i] != '\n')
	{
		i++;
	}
	close (fd);
	return (i);
}

int count_line(char *path)
{
	int i;
	char *str;
	int fd;
		
	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		free(str);
		i++;
	}
	close (fd);
	return (i);
}

int count_vars(t_vars *vars)
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
	if (count_vars(vars) == 1)
		error(vars);
}

int get_map(char *path, t_vars *vars)
{
	int i;
	int fd;
	char *str;

	i = 0;
	vars->line = count_line(path);
	vars->column = count_column(path);
	fd = open(path, O_RDONLY);
	vars->map = malloc (sizeof(char *) * vars->line + 1);
	while (i < vars->line)
	{
		str = get_next_line(fd);
		vars->map[i] = str;
		printf("%s", vars->map[i]);
		i++;
	}
	printf("\n");
	printf("Line: %d\nColumn: %d\n", vars->line, vars->column);
	close (fd);
	check_errors(vars);
	free_vars(vars);
	return (0);
}
