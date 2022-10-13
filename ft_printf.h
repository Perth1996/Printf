/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plawkiat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:32:40 by plawkiat          #+#    #+#             */
/*   Updated: 2022/10/12 07:07:58 by plawkiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *fmt, ...);
int		ft_char(int c);
int		ft_type(va_list args, const char *fmt, int i);
int		ft_string(char *s);
int		ft_countn(long n);
char	*ft_itoa(int N);
int		ft_putnbr(int nbr);
int		ft_strlen(const char *s);
int		ft_ulong(unsigned long n);
int		ft_uint(unsigned int n);
int		ft_x(unsigned int n, char x);

#endif
