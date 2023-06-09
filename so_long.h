/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:06:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/09 17:20:26 by egiubell         ###   ########.fr       */
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
	void	*img_monster;
	void	*img_ammo;
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
	int		ammo_count;
}	t_game;

#define TERRAIN "./assets/terrain.xpm"
#define WALL "./assets/wall.xpm"
#define PLAYER "./assets/player.xpm"
#define COLLECT "./assets/collect.xpm"
#define EXIT "./assets/exit.xpm"
#define MONSTER "./assets/monster.xpm"
#define AMMO "./assets/ammo.xpm"

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

int		close_winning(t_graph *graph);
int		close_losing(t_graph *graph);
int		pressed_x(t_graph *graph);

void	free_vars(t_game *game);
char	*ft_itoa(int n);

void	mlx_manage(t_game *game);


void	place_image(t_game *game);
void    put_correct_image(t_game *game);

int		hook_manage(int keycode, t_game *game);

void	direction_W(int id, t_game *game);
void    direction_S(int id, t_game *game);
void    direction_A(int id, t_game *game);
void    direction_D(int id, t_game *game);

//Bonus
void display_move_count(t_game *game);
void pick_ammo(t_game *game);

#endif
