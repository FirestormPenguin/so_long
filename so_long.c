/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:09:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/25 20:29:38 by egiubell         ###   ########.fr       */
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

int	close_win(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	return (0);
}

int	main()
{
	t_data	*data;
	t_vars vars;
	int i;
	int y;
	int x;

	data = (t_data *)malloc(sizeof(t_data));
	i = 50;
	y = 480;
	x = 640;
	vars.mlx = mlx_init();		//inizia mlx
	vars.win = mlx_new_window(vars.mlx, x, y, "Finestra!");		//genera finestra
	data->img = mlx_new_image(vars.mlx, x, y);		//genera immagine
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);		//gestice in maniera corretta dimensione e posizione dei pixel
	while (i < x - 50)
	{
		my_mlx_pixel_put(data, i, 50, 0x00FF00FF);		//genera pixel nell'immmagine
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, data->img, 0, 0);		//put immagine nella finestra
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);			//trigger evento chiusura finestra alla pressione di un tasto
	mlx_loop(vars.mlx);			//gestione loop finestra tenuta attiva
}
