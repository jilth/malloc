/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_dot(t_att *attr, int *i, const char **s)
{
	char	num[50];
	int		j;

	j = 0;
	while (**s == '.')
	{
		attr->dot = 1;
		(*s)++;
		(*i)++;
		while (ft_isdigit(**s) == 1)
		{
			num[j] = **s;
			j++;
			(*s)++;
			(*i)++;
		}
		num[j] = '\0';
		attr->dot_value = ft_atoi(num);
	}
}

void	deal_digits(const char **s, int *i, t_att *attr)
{
	char	dig[50];
	int		j;

	j = 0;
	attr->digits = 0;
	while (ft_isdigit(**s) == 1)
	{
		dig[j] = **s;
		j++;
		(*s)++;
		(*i)++;
	}
	dig[j] = '\0';
	if (j != 0)
		attr->digits = ft_atoi(dig);
	else
		attr->digits = 0;
}

void	star_case(t_att *attr, int *i, const char **s)
{
	attr->star = 0;
	while (**s == '*')
	{
		(*s)++;
		(*i)++;
		attr->star = 1;
	}
}

int		dot_case(t_att attr, int size)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (attr.dot == 1 && size < attr.dot_value)
	{
		k = attr.dot_value - size;
		while (i < k)
		{
			ft_putchar('0');
			i++;
		}
	}
	return (k);
}

size_t	digits_put(t_att attr, int size, char t)
{
	int			j;
	int			k;
	int			l;

	l = attr.digits;
	j = 0;
	k = size;
	if (l > k)
	{
		if (attr.dot_value > k && t != 's')
			k = attr.dot_value;
		k = l - k;
		while (j < k)
		{
			ft_putchar(' ');
			j = j + 1;
		}
		return (j);
	}
	return (0);
}
