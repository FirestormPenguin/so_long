/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:06:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/07 18:13:26 by egiubell         ###   ########.fr       */
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
	int		index_collect;
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

typedef struct s_game {
	t_vars *vars;
	t_graph graph;
	int		x;
	int		y;
	int		map_i;
	int		map_j;
	int		x_arrow;
	int		y_arrow;
	int		move_count;
}	t_game;

#define TERRAIN "./assets/terrain.xpm"
#define WALL "./assets/wall.xpm"
#define PLAYER "./assets/player/idle/frames_xpm/idle1.xpm"
#define COLLECT "./assets/collect.xpm"
#define EXIT "./assets/exit.xpm"

#define W 119
#define A 97
#define D 100
#define S 115
#define ESC 65307
#define TILESIZE 128

int		get_map(char *path, t_game *game);
int		count_line(char *path);
int		count_column(char *path);

void	check_errors(t_game *game);
int		checks_vars(t_game *game);
int		checks_format(t_game *game);
void	error(t_game *game, int id);

void	free_vars(t_game *game);

void	mlx_manage(t_game *game);
int		close_win(t_graph *graph);

void	place_image(t_game *game);
void    put_correct_image(t_game *game, int i, int j, int map_i, int map_j);

int		hook_manage(int keycode, t_game *game);

void	direction_W(int id, t_game *game);
void    direction_S(int id, t_game *game);
void    direction_A(int id, t_game *game);
void    direction_D(int id, t_game *game);

#endif
