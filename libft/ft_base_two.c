/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:16 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:16 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
static char	ft_tohex(int n, int caps)
{
	if (n < 10)
		return (n + '0');
	if (n == 10)
		return ('a' + caps);
	if (n == 11)
		return ('b' + caps);
	if (n == 12)
		return ('c' + caps);
	if (n == 13)
		return ('d' + caps);
	if (n == 14)
		return ('e' + caps);
	if (n == 15)
		return ('f' + caps);
	return (0);
}

char		*ft_itox(long int n)
{
	char	*val;
	int		i;
	int		neg;

	neg = 0;
	i = 0;
	val = (char *)malloc(sizeof(long int) + 1);
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	while (n > 16)
	{
		val[i] = ft_tohex(n % 16, -32);
		n = n / 16;
		i++;
	}
	val[i] = ft_tohex(n, -32);
	i++;
	if (neg == 1)
		val[i++] = '-';
	val[i] = '\0';
	return (ft_strrev(val));
}

char		*ft_itoh(long unsigned int n)
{
	char	*val;
	int		i;

	i = 0;
	val = (char *)malloc(sizeof(long int) + 1);
	while (n > 16)
	{
		val[i] = ft_tohex(n % 16, 0);
		n = n / 16;
		i++;
	}
	val[i] = ft_tohex(n, 0);
	i++;
	val[i] = '\0';
	return (ft_strrev(val));
}

char		*ft_itoc(long int n)
{
	char	*val;
	int		i;
	int		neg;

	neg = 0;
	i = 0;
	val = (char *)malloc(sizeof(long int) + 1);
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	while (n > 8)
	{
		val[i] = (n % 8) + '0';
		n = n / 8;
		i++;
	}
	val[i] = n + '0';
	i++;
	if (neg == 1)
		val[i++] = '-';
	val[i] = '\0';
	return (ft_strrev(val));
}
