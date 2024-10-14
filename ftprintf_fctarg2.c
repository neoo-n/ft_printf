/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_fctarg2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:37:07 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/14 18:12:58 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int n)
{
	int	nb_ten;
	int	count;
	int	temp;

	nb_ten = 1;
	count = nb_of_nb(n, 10);
	while (nb_ten > 0)
	{
		temp = n;
		temp = (temp / nb_ten) % 10 + '0';
		write(1, &temp, 1);
		nb_ten /= 10;
	}
	return (count);
}

int	print_xlow(unsigned int n)
{
	int				count;
	char			*s;
	unsigned long	nb_sixt;
	unsigned int	temp;

	count = 0;
	nb_sixt = 1;
	s = "0123456789abcdef";
	count += nb_of_nb((unsigned long) n, 16);
	while (nb_sixt > 0)
	{
		temp = n;
		temp = (temp / nb_sixt) % 16;
		write(1, &s[temp], 1);
		nb_sixt /= 16;
	}
	return (count);
}

int	print_xup(unsigned int n)
{
	int				count;
	char			*s;
	unsigned long	nb_sixt;
	unsigned int	temp;

	count = 0;
	nb_sixt = 1;
	s = "0123456789ABCDEF";
	count += nb_of_nb((unsigned long) n, 16);
	while (nb_sixt > 0)
	{
		temp = n;
		temp = (temp / nb_sixt) % 16;
		write(1, &s[temp], 1);
		nb_sixt /= 16;
	}
	return (count);
}
