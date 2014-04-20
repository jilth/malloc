/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreopt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:19 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:00:19 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_percent(t_att *attr, int *i, const char **s)
{
	while (**s == '%')
	{
		(*i)++;
		(*s)++;
		attr->percent = 1;
	}
}

size_t	put_percent(char c)
{
	ft_putchar('%');
	ft_putchar(c);
	return (2);
}
