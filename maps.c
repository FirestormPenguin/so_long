/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:13:49 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/29 20:17:07 by egiubell         ###   ########.fr       */
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
	vars->map = malloc (sizeof(char *) * vars->line);
	while (i < vars->line)
	{
		str = get_next_line(fd);
		vars->map[i] = malloc(sizeof(char *) * vars->column);
		vars->map[i] = str;
		printf("%s", vars->map[i]);
		i++;
	}
	printf("\nLines: %d\nColumns: %d\n", vars->line, vars->column);
	free(str);
	close (fd);
	return (0);
}
