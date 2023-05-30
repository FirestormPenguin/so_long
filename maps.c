/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 17:01:15 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_col(char *path)
{
	int i;
	char *str;
	int fd;
		
	i = 0;
	str = malloc(sizeof(char) * 50000);
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (str[i] != '\n')
	{
		i++;
	}
	while (str)
		str = get_next_line(fd);
	close (fd);
	free (str);
	return (i);
}

int count_line(char *path)
{
	int i;
	char *str;
	int fd;
		
	i = 0;
	str = malloc (sizeof(char) * 50000);
	fd = open(path, O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		i++;
	}
	free (str);
	close (fd);
	return (i - 1);
}

int count_vars(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < vars->line)
	{
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
	printf("P: %d\nE: %d\nC %d\n", vars->player, vars->exit, vars->collect);
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
	j = 0;
	while (i < vars->line)
	{
		while (j < vars->column)
		{
			if ((vars->map[0][j] != '1' || vars->map[vars->line - 1][j] != '1') || 
				(vars->map[i][0] != '1' || vars->map[i][vars->column - 1] != '1'))
				{
					printf("1\n");
					error(vars);
				}
			if (vars->map[i][j] != '0' && vars->map[i][j] != '1' && vars->map[i][j] != 'C' && 
				vars->map[i][j] != 'E' && vars->map[i][j] != 'P')
				{
					printf("2\n");
					error(vars);
				}
			j++;
		}
		i++;
	}
	if (count_vars(vars) == 1)
	{
		printf("3\n");
		error(vars);
	}
}

int get_map(char *path, t_vars *vars)
{
	int i;
	int fd;
	char *str;

	i = 0;
	vars->line = count_line(path);
	vars->column = count_col(path);
	fd = open(path, O_RDWR);
	str = malloc (sizeof(char) * 100);
	vars->map = malloc (sizeof(char *) * vars->line + 1);
	while (i < vars->line)
	{
		str = get_next_line(fd);
		vars->map[i] = malloc(sizeof(char *) * vars->column + 1);
		vars->map[i] = str;
		printf("%s", vars->map[i]);
		i++;
	}
	printf("\n");
	free(str);
	close (fd);
	check_errors(vars);
	return (0);
}
