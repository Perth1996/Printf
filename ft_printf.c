/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plawkiat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:52:40 by plawkiat          #+#    #+#             */
/*   Updated: 2022/10/12 07:03:31 by plawkiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list args, const char *fmt, int i)
{
	int	len;

	len = 0;
	if (fmt[i] == 'c')
		len += ft_char(va_arg(args, int));
	if (fmt[i] == 's')
		len += ft_string(va_arg(args, char *));
	if (fmt[i] == 'd' || fmt[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (fmt[i] == 'u')
		len += ft_uint(va_arg(args, unsigned int));
	if (fmt[i] == 'x')
		len += ft_x(va_arg(args, unsigned int), 'x');
	if (fmt[i] == 'X')
		len += ft_x(va_arg(args, unsigned int), 'X');
	if (fmt[i] == 'p')
	{
		len += ft_string("0x");
		len += ft_ulong(va_arg(args, unsigned long));
	}
	if (fmt[i] == '%')
		len += ft_char('%');
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, fmt);
	i = 0;
	len = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			len += ft_type(args, fmt, i + 1);
			i++;
		}
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end (args);
	return (len);
}
