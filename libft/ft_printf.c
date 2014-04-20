/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravenel <mravenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 11:50:00 by mravenel          #+#    #+#             */
/*   Updated: 2014/02/01 16:32:58 by mravenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_attr(t_att *attr)
{
	attr->sp = 0;
	attr->pl = 0;
	attr->sh = 0;
	attr->dot = 0;
	attr->dot_value = 0;
	attr->digits = 0;
	attr->percent = 0;
}

static void	deal_attr(t_att *attr, int *i, const char **s)
{
	set_attr(attr);
	deal_percent(attr, i, s);
	if (**s == '#')
	{
		attr->sh = 1;
		(*s)++;
		(*i)++;
	}
	deal_digits(s, i, attr);
	star_case(attr, i, s);
	while (**s == ' ')
	{
		attr->sp = 1;
		(*s)++;
		(*i)++;
	}
	deal_dot(attr, i, s);
	if (**s == '+')
		attr->pl = 1;
	if (**s == '+' || **s == '-')
	{
		(*s)++;
		(*i)++;
	}
}

static int	ft_find_type(const char *s, va_list ap, t_att attr)
{
	int		size;

	size = 0;
	if (attr.percent == 1)
		return (put_percent(*s));
	if (attr.star == 1)
		attr.digits = va_arg(ap, size_t);
	if (*s == 'd' || *s == 'i')
		return (size += d_case((long int)va_arg(ap, int), attr));
	if (*s == 'u')
		return (size += u_case(va_arg(ap, unsigned long int), attr));
	if (*s == 'o')
		return (size += o_case((unsigned long int)va_arg(ap, long int), attr));
	if (*s == 'x')
		return (size += x_case(va_arg(ap, long unsigned int), attr));
	if (*s == 'X')
		return (size += cx_case((unsigned long)va_arg(ap, long), attr));
	if (*s == 'c')
		return (size += c_case((unsigned char)va_arg(ap, int), attr));
	if (*s == 's')
		return (size += s_case(va_arg(ap, char *), attr));
	if (*s == 'p')
		return (size += p_case(va_arg(ap, long unsigned int), attr));
	return (size);
}

static int	ft_is_opt(const char *s, t_att *attr, int *i)
{
	deal_attr(attr, i, &s);
	if (*s == 'd' || *s == 'i' || *s == 'c' || *s == 's' || *s == 'u' \
		|| *s == 'o' || *s == 'x' || *s == 'X' || *s == 'p')
	{
		return (1);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			size;
	int			i;
	t_att		attr;

	size = 0;
	i = 0;
	va_start(ap, format);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%' \
			&& ft_is_opt(&(format[i + 1]), &attr, &i) == 1)
		{
			size += ft_find_type(&(format[i + 1]), ap, attr);
			i++;
		}
		else
			size += ft_print_str(format[i]);
		i++;
	}
	va_end(ap);
	return (size);
}
