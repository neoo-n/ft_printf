/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_fctarg1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:53:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/14 18:16:28 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_s(char *s)
{
	int		i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	nb_of_nb(unsigned long n, int base)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	print_p(unsigned long p)
{
	int				nb_sixt;
	int				i;
	char			*s;
	unsigned long	temp;

	nb_sixt = 2;
	i = 0;
	temp = p;
	s = "0123456789abcdef";
	write(1, "0x", 2);
	nb_sixt += nb_of_sixt(p, 16);
	while (nb_sixt > i)
	{
		
		write(1, &s[temp], 1);
	}
	return (count);
}

int	print_int(int n)
{
	int	nb_ten;
	int	count;
	int	temp;

	count = 0;
	nb_ten = 1;
	if (n == -2147483648)
		return (print_s("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		count++;
	}
	count += nb_of_nb(n, 10);
	while (nb_ten > 0)
	{
		temp = n;
		temp = (temp / nb_ten) % 10 + '0';
		write(1, &temp, 1);
		nb_ten /= 10;
	}
	return (count);
}	
