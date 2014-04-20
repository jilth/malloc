/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:16 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:28:28 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digits(int n)
{
	int		digits;

	digits = 0;
	if (n < 0)
		digits = 1;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char		*reverse_str(char *s)
{
	char	c;
	int		i;
	int		k;

	k = ft_strlen(s) - 1;
	i = 0;
	while (i < k)
	{
		c = s[i];
		s[i] = s[k];
		s[k] = c;
		k--;
		i++;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	r;
	char			*s;

	s = (char *)malloc(count_digits(n) + 1);
	if (s)
	{
		i = 0;
		if (n == 0)
			s[i++] = '0';
		if (n < 0)
			r = n * -1;
		else
			r = n;
		while (r > 0)
		{
			s[i++] = (char)(r % 10 + '0');
			r /= 10;
		}
		if (n < 0)
			s[i++] = '-';
		s[i] = '\0';
		return (reverse_str(s));
	}
	return (NULL);
}
