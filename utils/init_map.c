/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 18:44:25 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

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
	printf("Line: %d\nColumn: %d\n", vars->line, vars->column);
	close (fd);
	check_errors(vars);
	free_vars(vars);
	return (0);
}