/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:18:13 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/09 19:29:03 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	n_count(int n)
{
	size_t	i;
	int		a;

	i = 0;
	a = n;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		a = -a;
		i = 1;
	}
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return ((int)i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	i = n_count(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[i] = '\0';
	i--;
	while (n != 0 && str[i] != '-')
	{
		str[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	return (str);
}
