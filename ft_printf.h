/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:43:28 by dvauthey          #+#    #+#             */
/*   Updated: 2024/10/11 15:46:35 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	nb_of_nb(int n, int *nb_ten);
int	print_c(char c);
int	print_s(char *s);
int	print_p(void *p);
int	print_int(int n);
int	print_u(unsigned int n);
int	print_x(unsigned int n);
int	print_X(unsigned int n);
#endif
