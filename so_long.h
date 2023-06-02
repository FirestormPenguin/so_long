/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:06:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 21:37:37 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./minilibx/mlx.h"
#include "./include/get_next_line/get_next_line.h"
#include "./include/ft_printf/ft_printf.h"

typedef struct s_vars {
	char	**map;
	int		line;
	int		column;
	int		player;
	int		collect;
	int		exit;
}	t_vars;

typedef struct s_graph {
	void	*mlx;
	void	*win;
	void	*img_terrain;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_graph;

typedef struct s_move {
	int	direction;
	int	count;
}	t_move;

#define TERRAIN "./assets/terrain.xpm"
#define WALL "./assets/wall.xpm"
#define PLAYER "./assets/player/idle/frames_xpm/idle1.xpm"
#define COLLECT "./assets/collect.xpm"
#define EXIT "./assets/exit.xpm"
#define W 119
#define A 97
#define D 100
#define S 115

int		get_map(char *path, t_vars *vars);
int		count_line(char *path);
int		count_column(char *path);

void	check_errors(t_vars *vars);
int		checks_vars(t_vars *vars);
int		checks_format(t_vars *vars);
void	error(t_vars *vars, int id);

void	free_vars(t_vars *vars);

void	mlx_manage(t_graph graph, t_vars *vars, t_move move);
int		close_win(t_graph *graph);

void	place_image(t_graph graph, t_vars *vars, int x, int y);

void    movement(t_graph graph, t_move move);

#endif
