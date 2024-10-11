/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_fctarg1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:53:09 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/11 14:02:56 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_s(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		write(1, s[i], 1);
		i++;
	}
	return (i);
}

int	print_p(void *p)
{
	unsigned char	*temp;

	temp = p;
	write(1, "0x", 2);
	return (print_s(temp) + 2);
}

int	nb_of_nb(int n, int *nb_ten)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		nb_ten *= 10;
		n /= 10;
		i++;
	}
	nb_ten /= 10;
	return (i);
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
	count += nb_of_nb(n, &nb_ten);
	while (nb_ten > 0)
	{
		temp = n;
		temp /= nb_ten % 10 + '0';
		write(1, &temp, 1);
		nb_ten /= 10;
	}
	return (count);
}	
