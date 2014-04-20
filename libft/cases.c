/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravenel <mravenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:13:19 by mravenel          #+#    #+#             */
/*   Updated: 2014/02/01 17:15:55 by mravenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_case(unsigned long int nb, t_att attr)
{
	char	*str;
	char	*save;
	int		size;

	str = ft_itoh(nb);
	size = ft_strlen(str);
	if (attr.sh == 1)
		size += 2;
	if (attr.sh == 1 && attr.dot_value > 0)
		attr.dot_value += 2;
	size += digits_put(attr, size, 'n');
	if (attr.sh == 1)
	{
		ft_putstr("0x");
		size += dot_case(attr, ft_strlen(str) + 2);
		save = str;
		free(save);
	}
	else
		size += dot_case(attr, ft_strlen(str));
	ft_putstr(str);
	return (size);
}

int		p_case(unsigned long nb, t_att attr)
{
	char	*str;
	int		size;
	char	*save;

	str = ft_itoh(nb);
	save = str;
	size = ft_strlen(str);
	if (attr.dot_value > 0)
		attr.dot_value += 2;
	size += 2;
	size += digits_put(attr, size, 'n');
	ft_putstr("0x");
	size += dot_case(attr, ft_strlen(str) + 2);
	free(save);
	ft_putstr(str);
	return (size);
}

int		cx_case(unsigned long int nb, t_att attr)
{
	char	*str;
	int		size;
	char	*save;

	str = ft_itox(nb);
	size = ft_strlen(str);
	if (attr.sh == 1)
		size += 2;
	if (attr.sh == 1 && attr.dot_value > 0)
		attr.dot_value += 2;
	size += digits_put(attr, size, 'n');
	if (attr.sh == 1)
	{
		ft_putstr("0x");
		size += dot_case(attr, ft_strlen(str) + 2);
		save = str;
		free(save);
	}
	else
		size += dot_case(attr, ft_strlen(str));
	if (attr.sh == 1)
	ft_putstr(str);
	return (size);
}

int		o_case(unsigned long int nb, t_att attr)
{
	char	*str;
	int		size;

	str = ft_itoc(nb);
	size = ft_strlen(str);
	size += digits_put(attr, ft_strlen(str), 'n');
	size += dot_case(attr, ft_strlen(str));
	ft_putstr(str);
	ft_strdel(&str);
	return (size);
}

int		d_case(long int nb, t_att attr)
{
	char	*str;
	int		size;

	size = attr_cases(nb, attr);
	str = ft_itoa(nb);
	size += ft_strlen(str);
	size += digits_put(attr, ft_strlen(str), 'n');
	size += dot_case(attr, ft_strlen(str));
	ft_putstr(str);
	ft_strdel(&str);
	return (size);
}
