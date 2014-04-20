/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:02:26 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:33:25 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*s1_pt;
	const char		*s2_pt;

	s1_pt= (char *)s1;
	s2_pt = (char *)s2;
	while (n-- > 0)
	{
		*s1_pt++ = *s2_pt++;
		if (*(s1_pt - 1) == c)
			return (s1_pt);
	}
	return (NULL);
}
