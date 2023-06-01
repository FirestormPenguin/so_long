/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:54:17 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/01 17:40:02 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_graph *graph)
{
	mlx_destroy_window(graph->mlx, graph->win);
	printf("exit\n");
	exit(0);

}

// int render_next_frame(t_vars graph)
// {
// 	void *img;
// 	printf("enter\n");
// 	img = mlx_new_image(graph.mlx, 640, 480);
// 	return (0);
// }

void mlx_manage(t_graph graph)
{
    int img_width;
	int img_height;
    char *path = "./assets/Grass.xpm";
    
    graph.mlx = mlx_init();
    graph.win = mlx_new_window(graph.mlx, 640, 480, "Finestra!!");
    graph.img = mlx_xpm_file_to_image(graph.mlx, path, &img_width, &img_height);
    graph.addr = mlx_get_data_addr(graph.img, &graph.bits_per_pixel, &graph.line_length, &graph.endian);
    mlx_put_image_to_window(graph.mlx, graph.win, graph.img, 0, 0);
    mlx_hook(graph.win, 17, 1L << 17, close_win, &graph);
    mlx_loop(graph.mlx);
}
