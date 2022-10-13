/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plawkiat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:41:34 by plawkiat          #+#    #+#             */
/*   Updated: 2022/10/12 06:58:08 by plawkiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulong(unsigned long n)
{
	char	hex[16];
	int		i;
	int		c;

	c = 0;
	i = -1;
	if (n == 0 && n / 1 == 0)
	{
		ft_char('0');
		return (1);
	}
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		hex[++i] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	c = i + 1;
	while (i >= 0)
		write(1, &hex[i--], 1);
	return (c);
}

int	ft_x(unsigned int n, char x)
{
	char	hex[16];
	int		i;
	int		c;

	c = 0;
	i = -1;
	if (n == 0 && n / 1 == 0)
	{
		ft_char('0');
		return (1);
	}
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		if (x == 'x')
			hex[++i] = "0123456789abcdef"[n % 16];
		else
			hex[++i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	c = i + 1;
	while (i >= 0)
		write(1, &hex[i--], 1);
	return (c);
}

int	ft_char(int c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	ft_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_uint(unsigned int n)
{
	int		i;
	char	nbr[12];
	int		c;

	i = -1;
	c = 0;
	if (n == 0)
		c += ft_char('0');
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		(nbr[++i] = (n % 10) + '0');
		n /= 10;
		c += 1;
	}
	while (i >= 0)
		write (1, &nbr[i--], 1);
	return (c);
}
