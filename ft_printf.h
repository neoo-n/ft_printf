/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:43:28 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/14 18:31:40 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	nb_of_nb(unsigned long n, int base);
int ft_power(unsigned long n, int power);
int	print_c(int c);
int	print_s(char *s);
int	print_p(unsigned long p);
int	print_int(int n);
int	print_u(unsigned int n);
int	print_xlow(unsigned int n);
int	print_xup(unsigned int n);
#endif
