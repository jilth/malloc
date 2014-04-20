/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravenel <mravenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 12:05:33 by mravenel          #+#    #+#             */
/*   Updated: 2014/02/02 15:39:25 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned long n)
{
	char	*val;
	int		i;
	int		neg;

	neg = 0;
	i = 0;
	val = (char *)malloc(sizeof(unsigned long) + 1);
	while (n > 10)
	{
		val[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	val[i] = n + '0';
	i++;
	if (neg == 1)
		val[i++] = '-';
	val[i] = '\0';
	return (ft_strrev(val));
}
