/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:09:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/26 18:50:00 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int print ()
{
	printf("press\n");
	return (0);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("exit\n");
	exit (0);
	return (0);
}

int render_next_frame(t_vars vars)
{
	void *img;
	mlx_destroy_window(vars.mlx, vars.win);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Finestra!");
	printf("enter\n");
	img = mlx_new_image(vars.mlx, 640, 480);
	return (0);
}

int	main()
{
	t_data	*data;
	t_vars	vars;
	int i;
	int y;
	int x;
	int img_width;
	int img_height;
	char *path = "./assets/Grass.xpm";

	data = (t_data *)malloc(sizeof(t_data));
	i = 50;
	x = 640;
	y = 480;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "Finestra!");
	printf("enter\n");
	data->img = mlx_xpm_file_to_image(vars.mlx, path, &img_width, &img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	mlx_put_image_to_window(vars.mlx, vars.win, data->img, 0, 0);
	mlx_key_hook(vars.win, print, &vars);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);		//da capire come funge
	mlx_loop(vars.mlx);
}
