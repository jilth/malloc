/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:00:48 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:37:00 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen((char *)s2);
	while (i < n)
	{
		if (i >= len)
			s1[i] = '\0';
		else
			s1[i] = s2[i];
		i++;
	}
	return (s1);
}
