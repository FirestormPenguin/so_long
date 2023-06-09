/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:06:40 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/16 22:46:04 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./include/get_next_line/get_next_line.h"
# include "./include/ft_printf/ft_printf.h"

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
	void	*img_player2;
	void	*img_collect;
	void	*img_exit;
	void	*img_monster;
	void	*img_monster2;
	void	*img_ammo;
}	t_graph;

typedef struct s_game {
	t_vars	*vars;
	t_graph	graph;
	int		x;
	int		y;
	int		map_i;
	int		map_j;
	int		x_arrow;
	int		y_arrow;
	int		move_count;
	int		ammo_count;
	double	monster_animation_timer;
	int		monster_frame;
}	t_game;

# define TERRAIN	"./assets/terrain.xpm"
# define WALL		"./assets/wall.xpm"
# define PLAYER		"./assets/player.xpm"
# define PLAYER2	"./assets/player2.xpm"
# define COLLECT	"./assets/collect.xpm"
# define EXIT		"./assets/exit.xpm"
# define MONSTER	"./assets/monster.xpm"
# define MONSTER2	"./assets/monster2.xpm"
# define AMMO		"./assets/ammo.xpm"

# define W 119
# define A 97
# define D 100
# define S 115
# define ESC 65307
# define TILESIZE 128

# define FRAMERATE 60
# define ANIMATIONDELAY 10000

int		get_map(char *path, t_game *game);
int		count_line(char *path);
int		count_column(char *path);

void	check_errors(t_game *game);
int		checks_vars(t_game *game);
int		checks_format(t_game *game);
void	error(t_game *game, int id);

int		close_winning(t_game *game);
int		close_losing(t_game *game);
int		pressed_x(t_game *game);

void	free_vars(t_game *game);
void	free_graph(t_graph *graph);
char	*ft_itoa(int n);

void	mlx_manage(t_game *game);

void	place_image(t_game *game);
void	put_correct_image(t_game *game);

int		hook_manage(int keycode, t_game *game);

void	direction_w(t_game *game);
void	direction_s(t_game *game);
void	direction_a(t_game *game);
void	direction_d(t_game *game);

void	place_w(t_game *game);
void	place_s(t_game *game);
void	place_a(t_game *game);
void	place_d(t_game *game);

//Bonus
void	display_move_count(t_game *game);
int		monster_animation(t_game *game);
void	display_ammo(t_game *game);

#endif
