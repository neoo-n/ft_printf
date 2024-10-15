/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_fctarg1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:53:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/15 12:05:30 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	int	notgood;

	notgood = write(1, &c, 1);
	return (notgood);
}

int	print_s(char *s)
{
	int		i;
	int		isgood;

	i = 0;
	if (!s)
	{
		isgood = write(1, "(null)", 6);
		if (isgood == -1)
			return (isgood);
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

int	print_p(unsigned long p, int isox)
{
	char	*s;
	int		count;
	int		isgood;

	s = "0123456789abcdef";
	count = nb_of_nb(p, 16) + 2;
	if (isox)
	{
		isgood = write(1, "0x", 2);
		isox = 0;
		if (isgood == -1)
			return (-1);
	}
	if (p == 0)
		count++;
	if (p > 15)
		print_p(p / 16, isox);
	isgood = write(1, &s[p % 16], 1);
	if (isgood == -1)
		return (-1);
	return (count);
}

int	print_int(int n)
{
	int	count;
	int	isgood;

	count = 0;
	if (n == -2147483648)
		return (print_s("-2147483648"));
	if (n == 0)
		count++;
	if (n < 0)
	{
		n *= -1;
		isgood = write(1, "-", 1);
		if (isgood == -1)
			return (-1);
		count++;
	}
	count += nb_of_nb(n, 10);
	if (n > 9)
		print_int(n / 10);
	n = (n % 10) + '0';
	isgood = write(1, &n, 1);
	if (isgood == -1)
		return (-1);
	return (count);
}	
