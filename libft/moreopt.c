/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreopt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravenel <mravenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:48:34 by mravenel          #+#    #+#             */
/*   Updated: 2013/12/22 15:58:30 by mravenel         ###   ########.fr       */
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
