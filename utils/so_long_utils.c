/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:41:39 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/02 21:37:31 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

void free_vars(t_vars *vars)
{
	int i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free(vars);
}
