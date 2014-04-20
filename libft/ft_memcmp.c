/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:30:42 by noumazza          #+#    #+#             */
/*   Updated: 2013/12/31 13:38:12 by longuyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dst;
	size_t			i;

	if (n != 0)
	{
		src = (unsigned char*)s1;
		dst = (unsigned char*)s2;
		i = 0;
		while (i < n)
		{
			if (src[i] != dst[i])
				return (src[i] - dst[i]);
			i++;
		}
	}
	return (0);
}
