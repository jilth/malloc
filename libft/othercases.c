/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othercases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravenel <mravenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:17:36 by mravenel          #+#    #+#             */
/*   Updated: 2013/12/22 15:45:35 by mravenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_case(unsigned long int nb, t_att attr)
{
	char	*str;
	int		size;

	str = ft_utoa(nb);
	size = ft_strlen(str);
	size += digits_put(attr, ft_strlen(str), 'n');
	size += dot_case(attr, ft_strlen(str));
	ft_putstr(str);
	ft_strdel(&str);
	return (size);
}

int		c_case(unsigned char c, t_att attr)
{
	int			j;

	j = 0;
	if (attr.digits > 1)
	{
		while (j < attr.digits - 1)
		{
			ft_putchar(' ');
			j++;
		}
	}
	ft_putchar(c);
	return (j + 1);
}

int		s_case(char *str, t_att attr)
{
	int		size;

	size = 0;
	if (str == NULL)
	{
		size += digits_put(attr, 6, 's');
		ft_putstr(str);
		return (size + 6);
	}
	size += digits_put(attr, ft_strlen(str), 's');
	size += ft_strlen(str);
	ft_putstr(str);
	return (size);
}

int		attr_cases(long int nb, t_att attr)
{
	if (nb > 0 && attr.pl == 1)
	{
		ft_putchar('+');
		return (1);
	}
	if (attr.sp == 1)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

int		ft_print_str(char c)
{
	if (c == '%')
		return (0);
	ft_putchar(c);
	return (1);
}
