/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:55:33 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/14 16:25:01 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	which_type(va_list args, const char *s, int i)
{
	int	count;

	count = 0;
	if (s[i] == 'c')
		count += print_c(va_arg(args, int));
	if (s[i] == 's')
		count += print_s(va_arg(args, char *));
	if (s[i] == 'p')
		count += print_p(va_arg(args, unsigned long));
	if (s[i] == 'd' || s[i] == 'i')
		count += print_int(va_arg(args, int));
	if (s[i] == 'u')
		count += print_u(va_arg(args, unsigned int));
	if (s[i] == 'x')
		count += print_xlow(va_arg(args, unsigned int));
	if (s[i] == 'X')
		count += print_xup(va_arg(args, unsigned int));
	if (s[i] == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += which_type(args, s, i);
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
