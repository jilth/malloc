/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 21:00:16 by noumazza          #+#    #+#             */
/*   Updated: 2014/04/20 21:24:23 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_sign(const char str, int *sign)
{
	*sign = 1;
	if (str == '-' || str == '+')
	{
		if (str == '-')
		{
			*sign = -1;
		}
		return (1);
	}
	return (0);
}

static int		check_tab_return(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\v' || str[i] == '\r' || str[i] == '\f' || \
		str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;
	int		flag;

	i = 0;
	i = check_tab_return(str);
	i += check_sign(str[i], &sign);
	result = 0;
	flag = 0;
	if (str == NULL || ft_isdigit((int)str[i] == 0))
		return (0);
	while (str[i] != '\0' && ft_isdigit((int)str[i]))
	{
		if (ft_isdigit((int)str[i]) == 0 && !flag)
			return (0);
		result = result * 10 + str[i] - '0';
		flag = 1;
		i++;
	}
	return (sign * result);
}
