/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:09:43 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/29 18:56:57 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	close_win(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	printf("exit\n");
// 	exit (0);
// 	return (0);
// }

// int render_next_frame(t_vars vars)
// {
// 	void *img;
// 	printf("enter\n");
// 	img = mlx_new_image(vars.mlx, 640, 480);
// 	return (0);
// }

int	main(int ac, char **av)
{
	char *path;
	t_vars *vars;
	
	vars = (t_vars *)malloc (sizeof (t_vars));
	if (ac != 2)
		return (printf("no vars\n"), 0);
	path = av[1];
	get_map(path, vars);
}
