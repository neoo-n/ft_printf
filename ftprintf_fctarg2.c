/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_fctarg2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:37:07 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/11 15:27:10 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_u(unsigned int n)
{
	int	nb_ten;
	int count;
	int	temp;

	nb_ten = 1;
	count = nb_of_nb(n, nb_ten);	
	while (nb_ten > 0)
	{
		temp = n;
		temp /= 10 % 10 + '0';
		write(1, &temp, 1);
		nb_ten /= 10;
	}
	return (count);
}

int	print_x(unsigned int n)
{
	int		count;
	char	*s;

	count = 0;
	s = "0123456789abcdef";
	while (n > 15)
	{
		print_x(n / 16);
		count++;
	}
	print_x(n % 16);
	write(1, &s[n], 1);
	return (count);
}

int	print_X(unsigned int n)
{
	int		count;
	char	*s;

	count = 0;
	s = "0123456789ABCDEF";
	while (n > 15)
	{
		print_x(n / 16);
		count++;
	}
	print_x(n % 16);
	write(1, &s[n], 1);
	return (count);
}
