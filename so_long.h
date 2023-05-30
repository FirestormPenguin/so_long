/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:06:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 18:02:15 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./minilibx/mlx.h"
#include "./include/get_next_line/get_next_line.h"

typedef struct s_vars {
	char **map;
	int line;
	int column;
	int player;
	int collect;
	int exit;
}			t_vars;

int get_map(char *path, t_vars *vars);

void struct_init(t_vars *vars);

void error(t_vars *vars);

void free_vars(t_vars *vars);
