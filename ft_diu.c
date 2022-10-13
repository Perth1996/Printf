/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plawkiat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:23:32 by plawkiat          #+#    #+#             */
/*   Updated: 2022/10/12 06:53:40 by plawkiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}		

int	ft_countn(long n)
{
	int		i;
	long	a;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	a = n;
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int N)
{
	int		i;
	char	*str;
	long	n;

	n = N;
	i = ft_countn(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (N < 0)
		n = -n;
	str[i--] = '\0';
	if (n >= 0)
	{
		while (i >= 0)
		{
			str[i--] = (n % 10) + 48;
			n = n / 10;
		}
	}
	if (N < 0)
		*str = '-';
	return (str);
}

int	ft_putnbr(int nbr)
{
	int		i;
	char	*n;

	i = 0;
	if (nbr == -2147483648)
	{
		ft_string("-2147483648");
		return (11);
	}
	n = ft_itoa(nbr);
	while (i < ft_strlen(n))
	{
		write(1, &n[i], 1);
		i++;
	}
	free (n);
	return (i);
}
