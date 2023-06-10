/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:23:30 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/10 18:31:35 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	c;
	char	*buff;

	i = 0;
	rd = 1;
	buff = malloc(sizeof(char) * 100000);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (rd > 0)
	{
		rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1);
		buff[i++] = c;
		if (c == '\n')
			break ;
	}
	buff[i] = '\0';
	if (rd == -1 || i == 0 || (!buff[i - 1] && !rd))
		return (free(buff), NULL);
	return (buff);
}
