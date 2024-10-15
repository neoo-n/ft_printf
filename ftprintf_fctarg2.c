/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_fctarg2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:37:07 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/15 11:59:33 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int n)
{
	int	count;

	count = nb_of_nb(n, 10);
	if (n == 0)
		count++;
	if (n > 9)
		print_u(n / 10);
	n = (n % 10) + '0';
	write(1, &n, 1);
	return (count);
}

int	print_xlow(unsigned int n)
{
	int				count;
	char			*s;

	count = nb_of_nb((unsigned long) n, 16);
	s = "0123456789abcdef";
	if (n == 0)
		count++;
	if (n > 15)
		print_xlow(n / 16);
	write(1, &s[n % 16], 1);
	return (count);
}

int	print_xup(unsigned int n)
{
	int				count;
	char			*s;

	count = nb_of_nb((unsigned long) n, 16);
	s = "0123456789ABCDEF";
	if (n == 0)
		count++;
	if (n > 15)
		print_xup(n / 16);
	write(1, &s[n % 16], 1);
	return (count);
}
