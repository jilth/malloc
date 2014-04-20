/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravenel <mravenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 12:09:07 by mravenel          #+#    #+#             */
/*   Updated: 2014/02/01 17:15:15 by mravenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	char	*s_cp;
	size_t	i;

	i = ft_strlen(str);
	s_cp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	s_cp[i] = '\0';
	i--;
	while (*str != '\0')
	{
		s_cp[i] = *str;
		i--;
		str++;
	}
	return (s_cp);
}
