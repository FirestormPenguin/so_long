/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:42:20 by egiubell          #+#    #+#             */
/*   Updated: 2023/06/10 03:51:16 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		i += write(1, &s[i], 1);
	}
	return (i);
}

int	ft_putdigit(long long int n, int base)
{
	int		len;
	char	*hex = "0123456789abcdef";

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += write(1, "-", 1);
	}
	if (n >= base)
		len += ft_putdigit((n / base), base);
	len += write (1, &hex[n % base], 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 'c')
				len += ft_putchar(va_arg(arg, int));
			if (s[i + 1] == 's')
				len += ft_putstr(va_arg(arg, char *));
			if (s[i + 1] == 'd')
				len += ft_putdigit(va_arg(arg, int), 10);
			i = i + 1;
		}
		else
		{
			len += write(1, &s[i], 1);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
