/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:55:33 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/11 14:10:00 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	int	count;

	i = 0;
	count = 0;
	va_start(args, const char *);
	while (s[i])
	{
		if (s[i] == '%')
			{
				i++;
				if (s[i] == 'c')
					count += print_c(va_arg(args, char);
				if (s[i] == 's')
					count += printf_s(va_arg(args, char *));
				if (s[i] == 'p')
					count += print_p(va_arg(args, void *));
				if (s[i] == 'd' || s[i] == 'i')
					count += print_int(va_arg(args, int));
				if (s[i] == 'u')
					count += print_u(va_arg(args, unsigned int));
				if (s[i] == 'x')
					count += print_x(va_arg(args, unsigned int));
				if (s[i] == 'X')
					count += print_X(va_arg(args, unsigned int));
				if (s[i] == '%')
				{
					write(1, "%", 1);
					count++;
				}
				i++;
			}
		write(1, &s[i], 1);
		count++;
		i++;
	}
	return (i);
}
