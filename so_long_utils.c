/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:39 by egiubell          #+#    #+#             */
/*   Updated: 2023/05/30 16:51:44 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(t_vars *vars)
{
	printf("Error\n");
	free (vars);
	exit(0);
}

void struct_init(t_vars *vars)
{
	vars->line = 0;
	vars->column = 0;
	vars->player = 0;
	vars->collect = 0;
	vars->exit = 0;
}