/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:42:07 by noumazza          #+#    #+#             */
/*   Updated: 2014/02/02 15:33:42 by rthebaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	char			*temp_1;
	const char		*temp_2;

	i = 0;
	temp_1 = s1;
	temp_2 = s2;
	while (i < n)
	{
		temp_1[i] = temp_2[i];
		i++;
	}
	return (s1);
}
